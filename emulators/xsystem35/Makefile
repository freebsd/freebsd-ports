# ports collection makefile for:	AliceSoft System 3.5 on X
# Date created:		24 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xsystem35
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.aist-nara.ac.jp/~masaki-c/private/unitbase/xsys35/down/

MAINTAINER=	sf@FreeBSD.org
COMMENT=	AliceSoft System 3.5 on X Window System

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes

PKGMESSAGE=	${WRKSRC}/MESSAGE

DOC_FILES=	BUGS ChangeLog ChangeLog.1 FAQ GAMES.TXT GRFMT.TXT \
		INSTALL MISCGAME.TXT \
		README README.color README.joystick README.music \
		TECH.TXT THANKS TODO

EXAMPLES=	README.TXT \
		456atlach.inf 456ningen.inf 456zero.inf \
		ambi.inf atlach_new.inf dalk.inf darcrows.inf diabo.inf \
		drstop.inf hushaby.inf kakurezuki.inf katsumi.inf \
		kichiku.inf mamatoto.inf mamori.inf miko.inf mugen.inf \
		oudou.inf panyo.inf panyo_new.inf pascha.inf persiom.inf \
		progood.inf rance1.inf rance2.inf rance3.inf rance4.inf \
		seeinao.inf toushin.inf toushin2.inf

PATCHES=	pastel.diff

.include <bsd.port.pre.mk>

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
FREETYPE_CONFIG?=    ${LOCALBASE}/bin/freetype-config

CONFIGURE_ARGS=	--without-included-gettext \
		--with-cachesize=20 \
		--enable-midi=seq,extp,raw \
		--enable-cdrom=bsd,mp3
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-audio=oss,esd --with-default-output=esd
.else
CONFIGURE_ARGS+=	--enable-audio=oss --with-default-output=oss
.endif

.if defined(WITH_SDL)
LIB_DEPENDS+=   	SDL-1.1.5:${PORTSDIR}/devel/sdl12
CONFIGURE_ARGS+=	--enable-sdl
CONFIGURE_ENV+=		SDL_CONFIG="${SDL_CONFIG}"
.else
CONFIGURE_ARGS+= 	--disable-sdl
.endif

.if defined(WITH_FREETYPE)
CONFIGURE_ARGS+=	 --enable-ttf
.else
CONFIGURE_ARGS+=	--disable-ttf
.endif

.if ${ARCH} == "i386"
.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.else
CONFIGURE_ARGS+=	--enable-mmx
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.endif
.endif

pre-everything::
.if !defined(WITH_SDL)
	@${ECHO_MSG} '===> Define WITH_SDL to enable SDL support'
.endif
.if !defined(WITH_FREETYPE)
	@${ECHO_MSG} '===> Define WITH_FREETYPE to enable FreeType support'
.endif
.if ${ARCH} == "i386"
.if !defined(WITHOUT_MMX)
	@${ECHO_MSG} '===> Define WITHOUT_MMX to disable MMX routines'
.endif
.endif

post-extract:
	@${CP} ${WRKSRC}/INSTALL ${WRKSRC}/doc/INSTALL

post-patch:
	${FIND} ${WRKSRC}/src -type f |\
	${XARGS} ${GREP} -l '<SDL/SDL' /dev/null |\
	${XARGS} ${REINPLACE_CMD} -e 's,<SDL/,<,'; \
	done

pre-configure:
	@${TOUCH} ${WRKSRC}/aclocal.m4 \
		  ${WRKSRC}/Makefile.in \
		  ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xsystem35 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/instgame ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/locale/ja/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/ja.mo ${PREFIX}/share/locale/ja/LC_MESSAGES/xsystem35.mo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/xsystem35
	(cd ${WRKSRC}/doc;\
		${INSTALL_MAN} ${DOC_FILES} ${PREFIX}/share/doc/ja/xsystem35)
.endif
	@${MKDIR} ${PREFIX}/share/examples/xsystem35
	${INSTALL_DATA} ${WRKSRC}/src/xsys35rc.sample ${PREFIX}/share/examples/xsystem35
	@(cd ${WRKSRC}/contrib; \
		${INSTALL_DATA} ${EXAMPLES} ${PREFIX}/share/examples/xsystem35)
	@(cd ${WRKSRC}/patch; \
		${INSTALL_DATA} ${PATCHES} ${PREFIX}/share/examples/xsystem35)
	@${SED} -e s,PREFIX,${PREFIX}, ${PKGDIR}/pkg-message > ${WRKSRC}/MESSAGE
	@${CAT} ${WRKSRC}/MESSAGE

.include <bsd.port.post.mk>

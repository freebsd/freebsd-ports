# ports collection makefile for:	AliceSoft System 3.5 on X
# Date created:		24 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xsystem35
PORTVERSION=	1.7.2
PORTREVISION=	11
CATEGORIES=	emulators
MASTER_SITES=	http://8ne.sakura.ne.jp:20008/chika/unitbase/xsys35/down/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AliceSoft System 3.5/3.6/3.8/3.9 on X Window System

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_AUTOTOOLS=	autoconf:262 libtool:22
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
WANT_GNOME=	yes

PKGMESSAGE=	${WRKSRC}/MESSAGE

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}
PATCHES=	pastel.diff

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--without-included-gettext \
		--program-prefix="" \
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

#.if defined(WITH_SDL)
#USE_SDL=	sdl
#CONFIGURE_ARGS+=	--enable-sdl
#CONFIGURE_ENV+=		"CPPFLAGS=`$(SDL_CONFIG) --cflags`" \
#			"LIBS=`$(SDL_CONFIG) --libs`"
#.else
CONFIGURE_ARGS+=	--disable-sdl
#.endif

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

pre-everything::
#.if !defined(WITH_SDL)
#	@${ECHO_MSG} '===> Define WITH_SDL to enable SDL support'
#.endif

post-extract:
	@${CP} ${WRKSRC}/INSTALL ${WRKSRC}/doc/INSTALL

post-patch:
	${FIND} ${WRKSRC}/src -type f |\
	${XARGS} ${GREP} -l '<SDL/SDL' /dev/null |\
	${XARGS} ${REINPLACE_CMD} -e 's,<SDL/,<,'; \
	done

pre-configure:
	(cd ${WRKSRC}/libltdl; ${AUTOCONF})

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/instgame ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc;\
		${INSTALL_MAN} * ${DOCSDIR})
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/xsys35rc.sample ${EXAMPLESDIR}
	@(cd ${WRKSRC}/contrib; \
		${INSTALL_DATA} *.* ${EXAMPLESDIR})
	@(cd ${WRKSRC}/patch; \
		${INSTALL_DATA} ${PATCHES} ${EXAMPLESDIR})
	@${SED} -e s,PREFIX,${PREFIX}, ${PKGDIR}/pkg-message > ${WRKSRC}/MESSAGE
	@${CAT} ${WRKSRC}/MESSAGE

.include <bsd.port.post.mk>

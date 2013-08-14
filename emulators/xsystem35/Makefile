# Created by: Seiichirou Hiraoka
# $FreeBSD$

PORTNAME=	xsystem35
PORTVERSION=	1.7.2
PORTREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	http://8ne.sakura.ne.jp:20008/chika/unitbase/xsys35/down/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AliceSoft System 3.5/3.6/3.8/3.9 on X Window System

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	ESOUND DOCS EXAMPLES

USES=		gettext
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf libtool
CONFIGURE_ARGS=	--without-included-gettext \
		--with-cachesize=20 \
		--enable-midi=seq,extp,raw \
		--enable-cdrom=bsd,mp3

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MESOUND}
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--enable-audio=oss,esd --with-default-output=esd
.else
CONFIGURE_ARGS+=	--enable-audio=oss --with-default-output=oss
.endif

#.if ${PORT_OPTIONS:MSDL}
#USE_SDL=	sdl
#CONFIGURE_ARGS+=	--enable-sdl
#CPPFLAGS+=	$$(${SDL_CONFIG} --cflags)
#LDFLAGS+=	$$(${SDL_CONFIG} --libs)
#.else
CONFIGURE_ARGS+=	--disable-sdl
#.endif

.if ${MACHINE_CPU:Mmmx} && !defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-mmx
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-extract:
	@${CP} ${WRKSRC}/INSTALL ${WRKSRC}/doc/INSTALL

post-patch:
	${FIND} ${WRKSRC}/src -type f |\
		${XARGS} ${GREP} -l '<SDL/SDL' /dev/null |\
		${XARGS} ${REINPLACE_CMD} -e 's,<SDL/,<,'
	@${REINPLACE_CMD} -e \
		's|__COUNTER__|__COUNTER_H__|' ${WRKSRC}/src/counter.h

pre-configure:
	(cd ${WRKSRC}/libltdl; ${AUTOCONF})

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/instgame ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc;\
		${INSTALL_DATA} * ${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/xsys35rc.sample ${EXAMPLESDIR}
	@(cd ${WRKSRC}/contrib; \
		${INSTALL_DATA} *.* ${EXAMPLESDIR})
	@(cd ${WRKSRC}/patch; \
		${INSTALL_DATA} pastel.diff ${EXAMPLESDIR})
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

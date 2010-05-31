# New ports collection makefile for:	warzone2100
# Date created:				21 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	warzone2100
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Warzone%202100%20${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Innovative 3D real-time strategy game

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		mad.2:${PORTSDIR}/audio/libmad \
		ogg.6:${PORTSDIR}/audio/libogg \
		physfs.1:${PORTSDIR}/devel/physfs \
		png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		GLC.0:${PORTSDIR}/graphics/quesoglc \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSans.ttf:${PORTSDIR}/x11-fonts/dejavu

USE_BISON=	build
GNU_CONFIGURE=	yes
USE_OPENAL=	al
USE_GL=		yes
USE_GMAKE=	yes
USE_SDL=	net sdl
CONFIGURE_ARGS=	--program-transform-name="" --with-distributor="FreeBSD ports"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS}" \
		PATH="${LOCALBASE}/bin:$$PATH"
REINPLACE_ARGS=	-i ''
MAKE_JOBS_SAFE=	yes
PORTDOCS=	*

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700004
BROKEN=		Does not build
.endif

post-patch:
	@${REINPLACE_CMD} -e '/_XOPEN_SOURCE/ d' ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|NSIG|32|g; s|SIGPOLL|SIGIO|g' \
		${WRKSRC}/lib/exceptionhandler/exceptionhandler.c
	@${REINPLACE_CMD} -e '/include.*alloca/ d' \
		${WRKSRC}/lib/framework/config-macosx.h \
		${WRKSRC}/lib/framework/resource_parser.tab.c \
		${WRKSRC}/lib/framework/strres_parser.tab.c \
		${WRKSRC}/lib/framework/wzglobal.h \
		${WRKSRC}/lib/gamelib/audp_parser.tab.c \
		${WRKSRC}/lib/script/chat_parser.tab.c \
		${WRKSRC}/lib/script/script_parser.tab.c \
		${WRKSRC}/src/message_parser.tab.c \
		${WRKSRC}/src/scriptvals_parser.tab.c
	@${REINPLACE_CMD} -e 's|-m32||; s|-Werror||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|AUTHORS||; s|COPYING COPYING\.README||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/typedef void (\*__GLXextFuncPtr)(void);/d' \
		${WRKSRC}/lib/ivis_opengl/GLee.h
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee 's|install-dist_docDATA$$||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^install: install-am|install:|' \
		${WRKSRC}/doc/Makefile.in
.else
.endif

.include <bsd.port.post.mk>

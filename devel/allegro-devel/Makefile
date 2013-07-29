# Created by:	nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	allegro
DISTVERSION=	5.0.7
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
PKGNAMESUFFIX=	-devel5

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Cross-platform library for games and multimedia programming

LICENSE=	BSD

LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib \
		jack.0:${PORTSDIR}/audio/jack \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		physfs.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:${PORTSDIR}/textproc/hs-pandoc

USES=		gmake cmake pkgconfig
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_LDCONFIG=	yes
USE_OPENAL=	soft
USE_GL=		gl glu
USE_FREETYPE=	yes

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	allegro-[0-9]*
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"
CMAKE_ARGS+=	-DDOCDIR="${DOCSDIR}"

SHLIB_VER=	5.0.7

PORTSCOUT=	limit:^4\.3\.[0-9]*

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEMOS
OPTIONS_DEFAULT=	DEMOS
DEMOS_DESC=	Install Demos programs

.include <bsd.port.options.mk>
.include "Makefile.man"

.if ${PORT_OPTIONS:MDEMOS}
CMAKE_ARGS+=-DWANT_DEMO=on
PLIST_SUB+=DEMOS=""
.else
CMAKE_ARGS+=-DWANT_TESTS=off
.endif

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	CHANGES-5.0.txt CONTRIBUTORS.txt README.txt README_packaging.txt README_pkgconfig.txt

post-install:
	@${CP} -p ${WRKSRC}/allegro5.cfg ${PREFIX}/etc/allegro5.cfg.sample

.if ${PORT_OPTIONS:MEXAMPLES}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.if ${PORT_OPTIONS:MDEMOS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR})
.endif

.if ${PORT_OPTIONS:MMANPAGES}
	@cd ${WRKSRC}/docs/man/ && \
		${FIND} . -type f -and -name "*.3" -exec ${INSTALL_MAN} {} ${PREFIX}/man/man3/{} \;
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "src html" ${DOCSDIR})
.endif

.include <bsd.port.mk>

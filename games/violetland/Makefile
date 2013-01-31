# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	violetland
PORTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top-down survival shoot 'em up

LIB_DEPENDS=	boost_filesystem:${PORTSDIR}/devel/boost-libs

USE_ZIP=	yes
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_DOS2UNIX=	yes
CMAKE_ARGS=	-DDATA_INSTALL_DIR="${DATADIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}-v${PORTVERSION}

PORTDOCS=	CHANGELOG README_EN.TXT README_RU.TXT


.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/set.libList/ s|)| ${LOCALBASE}/lib/libintl.so&|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	designer
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 graphical user interface designer

USE_QT5=	assistant_run core gui network printsupport webkit \
		widgets xml buildtools_build
QT_DIST=	tools
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

DESKTOP_ENTRIES="Qt 5 Designer" "" \
		"${PREFIX}/share/pixmaps/designer-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/designer" \
		"Development;Qt;" true

WRKSRC_SUBDIR=	src/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/uitools/ d' \
		${WRKSRC}/src/src.pro

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/designer/images/designer.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/designer-qt5.png

.include <bsd.port.mk>

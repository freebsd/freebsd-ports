# $FreeBSD$

PORTNAME=	qdoc
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation generator

USE_QT5=	core xml buildtools_build qmake_build
QT_DIST=	base
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-dbus -no-gui -no-xcb

BUILD_WRKSRC=	${WRKSRC}/src/tools/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

QT_DOCDIR=      ${PREFIX}/share/doc/qt5

post-install:
	${MKDIR} ${STAGEDIR}${QT_DOCDIR} && \
	cd ${WRKSRC}/doc/global && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${QT_DOCDIR}/global


.include <bsd.port.mk>

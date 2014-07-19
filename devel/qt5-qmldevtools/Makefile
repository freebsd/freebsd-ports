# $FreeBSD$

PORTNAME=	qmldevtools
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QML development support module

USE_QT5=	core buildtools_build
QT_DIST=	declarative
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

WRKSRC_SUBDIR=	src/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's/no_module_headers//' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>

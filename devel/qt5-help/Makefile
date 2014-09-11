# $FreeBSD$

PORTNAME=	help
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt online help integration module

USE_QT5=	clucene core gui network sql widgets buildtools_build
QT_DIST=	tools
USES=		qmake
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

WRKSRC_SUBDIR=	src/assistant

post-patch:
	@${REINPLACE_CMD} -Ee 's,(clucene|assistant),,' \
		${WRKSRC}/assistant.pro

.include <bsd.port.mk>

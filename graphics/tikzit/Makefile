PORTNAME=	tikzit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.6
PORTREVISION=	33
CATEGORIES=	graphics

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	PGF/TikZ diagram editor
WWW=		https://tikzit.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on unsupported Qt5
EXPIRATION_DATE=	2027-01-01

LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5

USES=		bison compiler:c++11-lang qmake qt:5

USE_GITHUB=	yes

USE_QT=	buildtools core gui widgets network

.include <bsd.port.mk>

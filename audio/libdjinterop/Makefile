PORTNAME=	libdjinterop
DISTVERSION=	0.20.2
CATEGORIES=	audio

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	C++ library for access to DJ record libraries
WWW=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs # for test programs

USES=		compiler:c++17-lang cmake:testing sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	xsco

USE_LDCONFIG=	yes

PORTSCOUT=	ignore:1 # audio/mixxx dictates us
PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>

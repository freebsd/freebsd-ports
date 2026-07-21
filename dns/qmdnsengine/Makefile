PORTNAME=	qmdnsengine
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multicast DNS library for Qt applications
WWW=		https://github.com/nitroshare/qmdnsengine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lang qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	nitroshare
USE_QT=		base tools:build
USE_LDCONFIG=	yes

.include <bsd.port.mk>

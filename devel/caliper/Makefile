PORTNAME=	caliper
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Instrumentation and performance profiling library
WWW=		https://software.llnl.gov/Caliper/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lib python shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	python/cali2traceevent \
		python/cali2traceevent.py

USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Caliper

.include <bsd.port.mk>

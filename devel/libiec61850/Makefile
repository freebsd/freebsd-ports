PORTNAME=	libiec61850
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	open-source library for the IEC 61850 protocols
WWW=		http://libiec61850.com/libiec61850

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang dos2unix
USE_GITHUB=	yes
GH_ACCOUNT=	mz-automation

CMAKE_OFF=	BUILD_EXAMPLES
CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

.include <bsd.port.mk>

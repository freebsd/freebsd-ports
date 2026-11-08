PORTNAME=	popt
PORTVERSION=	1.19
PORTEPOCH=	2
CATEGORIES=	devel
#MASTER_SITES=	https://ftp.osuosl.org/pub/rpm/popt/releases/popt-1.x/ \
#		http://ftp.rpm.org/popt/releases/popt-1.x/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C library for parsing command line parameters
WWW=		https://github.com/rpm-software-management/popt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe iconv

CMAKE_OFF=	BUILD_DOCUMENTATION \
		ENABLE_ASAN \
		ENABLE_UBSAN \
		ENABLE_WERROR
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	popt_project

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management
GH_TAGNAME=	14c42b4

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>

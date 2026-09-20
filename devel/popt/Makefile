PORTNAME=	popt
DISTVERSION=	1.19.20260818
CATEGORIES=	devel
#MASTER_SITES=	https://ftp.osuosl.org/pub/rpm/popt/releases/popt-1.x/ \
#		http://ftp.rpm.org/popt/releases/popt-1.x/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Getopt(3) like library with a number of enhancements, from Redhat
WWW=		https://github.com/rpm-software-management/popt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing cpe iconv pathfix
CPE_VENDOR=	popt_project
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rpm-software-management
GH_TAGNAME=	14c42b4

CMAKE_ON=	MAKE_DISABLE_FIND_PACKAGE_Doxygen

post-install:
	${INSTALL_MAN} ${WRKSRC}/popt.3 ${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.mk>

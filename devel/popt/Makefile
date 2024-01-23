PORTNAME=	popt
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://ftp.osuosl.org/pub/rpm/popt/releases/popt-1.x/ \
		http://ftp.rpm.org/popt/releases/popt-1.x/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Getopt(3) like library with a number of enhancements, from Redhat
WWW=		https://github.com/rpm-software-management/popt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe iconv libtool pathfix

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

CPE_VENDOR=	popt_project

OPTIONS_DEFINE=	NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime localbase
OPTIONS_SUB=	yes

.include <bsd.port.mk>

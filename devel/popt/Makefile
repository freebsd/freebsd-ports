# Created by: Yuan-Chen Cheng <ycheng@sinica.edu.tw>
# $FreeBSD$

PORTNAME=	popt
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.rpm.org/popt/releases/popt-1.x/

MAINTAINER=	jpaetzel@FreeBSD.org
COMMENT=	Getopt(3) like library with a number of enhancements, from Redhat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv libtool pathfix

TEST_TARGET=	check

OPTIONS_DEFINE=	NLS

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime localbase
OPTIONS_SUB=	yes

.include <bsd.port.mk>

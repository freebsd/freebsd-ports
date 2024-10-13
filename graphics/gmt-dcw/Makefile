PORTNAME=	dcw-gmt
DISTVERSION=	2.1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.soest.hawaii.edu/dcw/ \
		https://gmt.mirror.ac.za/ \
		ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Digital Chart of the World for GMT 5 or later
WWW=		https://www.soest.hawaii.edu/wessel/dcw/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

NO_BUILD=	YES
NO_ARCH=	YES

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dcw* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

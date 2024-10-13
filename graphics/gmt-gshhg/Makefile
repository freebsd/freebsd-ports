PORTNAME=	gshhg-gmt
DISTVERSION=	2.3.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.soest.hawaii.edu/pwessel/gshhg/ \
		ftp://ftp.soest.hawaii.edu/gshhg/ \
		https://gmt.mirror.ac.za/gmt/ \
		ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Global Self-consistent, Hierarchical, High-resolution Geography
WWW=		https://www.soest.hawaii.edu/wessel/gshhg/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

NO_BUILD=	YES
NO_ARCH=	YES

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.nc ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

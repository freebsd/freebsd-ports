PORTNAME=	dcw-gmt
DISTVERSION=	2.1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.soest.hawaii.edu/%SUBDIR%/ \
		ftp://ftp.geologi.uio.no/pub/%SUBDIR%/ \
		ftp://ftp.iag.usp.br/%SUBDIR%/ \
		ftp://ftp.scc.u-tokai.ac.jp/pub/%SUBDIR%/ \
		http://gd.tuwien.ac.at/graphics/visual/%SUBDIR%/ \
		http://gmt.mirror.ac.za/%SUBDIR%/ \
		ftp://ftp.soest.hawaii.edu/gshhg/:gshhg \
		ftp://ftp.scc.u-tokai.ac.jp/pub/gmt/:gshhg
MASTER_SITE_SUBDIR=	gmt gmt/legacy

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Digital Chart of the World for GMT 5 or later
WWW=		https://www.soest.hawaii.edu/wessel/dcw/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

NO_BUILD=YES
NO_ARCH=YES

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} dcw* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

# New ports collection makefile for:    mendexk-euc
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mendexk
PORTVERSION=	2.4d
PKGNAMESUFFIX=	-euc
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/web2c/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${KPATHSEA_PARENT}${EXTRACT_SUFX}

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

USE_GMAKE=	yes
DIST_SUBDIR=	ptex

MANLANG=	ja
MAN1=		mendex.1

KPATHSEA_PARENT=	web2c-7.2

pre-configure:
	@( cd ${WRKDIR}/${KPATHSEA_PARENT}/kpathsea ; \
	    ./configure --prefix=${PREFIX} )

do-build:
	@( cd ${WRKDIR}/${KPATHSEA_PARENT}/kpathsea ; ${GMAKE} )
	@( cd ${WRKSRC} ; ${MAKE} kpathsea_parent=../${KPATHSEA_PARENT} )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mendex ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/${MANLANG}/man1
	@${INSTALL_MAN} ${WRKSRC}/mendex.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mendex
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mendex
.endif

.include <bsd.port.mk>

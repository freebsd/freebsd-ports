# New ports collection makefile for:    mendexk-sjis
# Version required:     2.4b
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1998/04/25 16:04:07 kuriyama Exp $
#

DISTNAME=	mendexk2.4b
PKGNAME=	ja-mendexk-sjis-2.4b
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex218/web2c/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${KPATHSEA_PARENT}${EXTRACT_SUFX}

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

USE_GMAKE=	yes
DIST_SUBDIR=	ptex

MANLANG=	ja
MAN1=		mendex.1

KPATHSEA_PARENT=	web2c-7.2

KANJI_FILES=	kana.h ktable.h

pre-configure:
	@( cd ${WRKDIR}/${KPATHSEA_PARENT}/kpathsea ; \
	    ./configure --prefix=${PREFIX} )
	@( cd ${WRKSRC} ; \
	    for i in ${KANJI_FILES}; do \
	      ${MV} $$i $$i.orig ; \
	      nkf -s $$i.orig > $$i ; \
	    done )

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

# New ports collection makefile for:    hpscat-1.3jshin
# Version required:     1.3jshin
# Date created:         4 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.3 1997/10/12 15:08:06 max Exp $
#

DISTNAME=	hpscat-jshin
PKGNAME=	ko-hpscat-1.3jshin
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/print/hpscat/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/editor/ked/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/print/hpscat/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/editor/ked/
DISTFILES=	hpscat-jshin.tar.gz ked.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=    hcode:${PORTSDIR}/korean/hcode

pre-configure:
	${CP} ${FILESDIR}/hpscat.sh ${WRKSRC}/

do-install:
	@cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_PROGRAM} hpscat ${PREFIX}/bin/hpscat.bin; \
	${INSTALL_SCRIPT} hpscat.sh ${PREFIX}/bin/hpscat; \
	${INSTALL_DATA} ${WRKDIR}/ked/Header ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_DATA} ${WRKDIR}/ked/Munjo ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_DATA} ${WRKDIR}/ked/MunjoBold ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_DATA} ${WRKDIR}/ked/PCMunjo ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_DATA} ${WRKDIR}/ked/Gotic ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_DATA} README ${PREFIX}/share/fonts/ked-hpscat; \
	${INSTALL_DATA} README.jshin ${PREFIX}/share/fonts/ked-hpscat;\
	${INSTALL_DATA} README.jshin.ks ${PREFIX}/share/fonts/ked-hpscat

.include <bsd.port.mk>

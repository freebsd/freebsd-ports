# New ports collection makefile for:    hmconv
# Version required:     1.0p3
# Date created:         31 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

DISTNAME=	hmconv1.0pl3
PKGNAME=	ko-hmconv-1.0p3
CATEGORIES=	korean mail
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/code/hmconv/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/code/hmconv/

MAINTAINER=	junker@jazz.snu.ac.kr

WRKSRC=		${WRKDIR}/hmconv

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hmconv ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/hmailedit ${PREFIX}/bin

.include <bsd.port.mk>

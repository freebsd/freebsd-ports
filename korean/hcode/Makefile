# New ports collection makefile for:    hcode
# Version required:     2.1mailpatch2
# Date created:         31 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/05/03 21:43:56 max Exp $
#

DISTNAME=	hcode2.1-mailpatch2
PKGNAME=	kr-hcode-2.1.2
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/code/hcode/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/code/hcode/

MAINTAINER=	junker@jazz.snu.ac.kr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hcode ${PREFIX}/bin

.include <bsd.port.mk>

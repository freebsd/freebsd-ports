# New ports collection makefile for:    hcode
# Version required:     2.1mailpatch3
# Date created:         31 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

DISTNAME=	hcode2.1-mailpatch3
PKGNAME=	ko-hcode-2.1.3
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/incoming/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/incoming/

MAINTAINER=	junker@jazz.snu.ac.kr

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hcode ${PREFIX}/bin

.include <bsd.port.mk>

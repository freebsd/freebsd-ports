# New ports collection makefile for:    hcode
# Date created:         31 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hcode
PORTVERSION=	2.1.3
CATEGORIES=	korean
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/incoming/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/incoming/
		
DISTNAME=	hcode2.1-mailpatch3

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Hangul code conversion utility

PLIST_FILES=	bin/hcode

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hcode ${PREFIX}/bin

.include <bsd.port.mk>

# New ports collection makefile for:    hmconv
# Date created:         31 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hmconv
PORTVERSION=	1.0.3
CATEGORIES=	korean mail
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/code/hmconv/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/code/hmconv/
DISTNAME=	hmconv1.0pl3

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Hangul code conversion utility for E-mail

WRKSRC=		${WRKDIR}/hmconv

pre-build:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hmconv ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/hmailedit ${PREFIX}/bin

.include <bsd.port.mk>

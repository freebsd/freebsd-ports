# New ports collection makefile for:    nhpf-1.42
# Date created:         25 May 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	nhpf
PORTVERSION=	1.42
CATEGORIES=	korean www
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Hangul Printing Filter for Netscape with embedded font

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/nhpf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nhpf
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nhpf
.endif
	@strip ${PREFIX}/bin/nhpf

.include <bsd.port.mk>

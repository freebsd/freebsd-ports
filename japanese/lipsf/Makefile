# New ports collection makefile for: lipsf
# Version required:	1.14a
# Date created:		6 Dec 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	lpsf114a
PKGNAME=	ja-lipsf-1.14a
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/unix/writing/print/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mita@jp.FreeBSD.org

WRKSRC=		${WRKDIR}/lipsf-114a

MANLANG=	ja
MAN1=		lipsf.1 pols.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lipsf
.for file in HISTORY Install README TECHKNOW
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/lipsf
.endfor
.endif

.include <bsd.port.mk>

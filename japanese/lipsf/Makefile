# New ports collection makefile for: lipsf
# Date created:		6 Dec 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lipsf
PORTVERSION=	2.00
CATEGORIES=	japanese print
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/lipsf/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	mita@jp.FreeBSD.org
COMMENT=	Text to LIPS filter

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//}

MANLANG=	ja
MAN1=		lipsf.1 pols.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in HISTORY Install README TECHKNOW
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

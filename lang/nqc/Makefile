# New ports collection makefile for:	nqc
# Date created:        11 Aug 1999
# Whom:                kbyanc
#
# $FreeBSD$
#

PORTNAME=	nqc
PORTVERSION=	3.1.r2
CATEGORIES=	lang
MASTER_SITES=	http://bricxcc.sourceforge.net/nqc/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhay@FreeBSD.org
COMMENT=	A compiler for writing programs for the Lego RCX

USE_GMAKE=	yes
CC=		${CXX}

MAN1=		nqc.1
PLIST_FILES=	bin/nqc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nqc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nqc-man-2.1r1-0.man ${PREFIX}/man/man1/nqc.1

.include <bsd.port.mk>

# New ports collection makefile for:	ghtool
# Date created:		19 September 2000
# Whom:			roam@orbitel.bg
#
# $FreeBSD$
#

PORTNAME=	ghtool
PORTVERSION=	1.0
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=gh-tool
DISTNAME=	ghmain.c
EXTRACT_SUFX=

MAINTAINER=	roam@FreeBSD.org
COMMENT=	"A command-line interface to the resolver library"

WRKSRC=		${WRKDIR}

TGT=		gh
SRC=		gh.c

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}/${SRC}
PLIST_FILES=	bin/gh

do-build:
		${CC} ${CFLAGS} -o ${WRKSRC}/${TGT} ${WRKSRC}/${SRC}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${TGT} ${PREFIX}/bin

.include <bsd.port.mk>

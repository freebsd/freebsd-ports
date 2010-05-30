# New ports collection makefile for:   smake
# Date created:        22 February 2005
# Whom:                Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smake
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.berlios.de/pub/smake/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./a/}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Highly portable make program with automake features

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	INS_BASE=${PREFIX}

MAN1=		smake.1
MAN5=		makefiles.5 makerules.5

RULEUSED=	"`${WRKSRC}/conf/oarch.sh`"
PLIST_SUB=	RULESUSED="${RULEUSED}"

.include <bsd.port.mk>

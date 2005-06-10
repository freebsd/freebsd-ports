# New ports collection makefile for:   smake
# Date created:        22 February 2005
# Whom:                Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	smake
PORTVERSION=	1.2.a.30
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.berlios.de/pub/smake/alpha/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./a/}

MAINTAINER=	martin@matuska.org
COMMENT=	Highly portable make program with automake features

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	INS_BASE=${PREFIX}

MAN1=		smake.1
MAN5=		makefiles.5 makerules.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	mob
# Date created:		01 Jan 2001
# Whom:			Assar Westerlund <assar@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mob
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://steamboat.cs.ucsb.edu/mob/src/
DISTNAME=	${PORTNAME}-1.0-BETA
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory Organization Benchmarks

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "powerpc"
BROKEN=		Configure fails on amd64, ia64, or powerpc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/inspector ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mob
	${INSTALL_DATA} ${WRKSRC}/doc/mob.ps ${PREFIX}/share/doc/mob
.endif

.include <bsd.port.post.mk>

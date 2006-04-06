# New ports collection makefile for:	festlex-cmu
# Date created:        			2000-06-15
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:58 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festlex-cmu
PORTVERSION=	1.95
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	festlex_CMU
DIST_SUBDIR=	festival
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CMU American English pronunciation dictionary for Festival

NO_BUILD=	yes
FHOME=		${PREFIX}/share/festival

do-install:
	${TAR} -C ${FHOME:H} -xzvpf ${_DISTDIR}/${_DISTFILES}

.include <bsd.port.mk>

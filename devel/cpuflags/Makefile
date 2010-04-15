# New ports collection makefile for:	cpuflags
# Date created:				2010/02/28
# Whom:                        		Quentin Stievenart <acieroid@awesom.eu>
#
# $FreeBSD$
# $NetBSD: Makefile,v 1.149 2009/11/12 05:38:58 obache Exp $

PORTNAME=	cpuflags
PORTVERSION=	1.41
CATEGORIES=	devel sysutils
MASTER_SITES=	http://awesom.eu/~acieroid/files/ports/${PORTNAME}/

MAINTAINER=	acieroid@awesom.eu
COMMENT=	Determine compiler flags to best target current cpu

post-install:
	${REINPLACE_CMD} -i '' -e "s,@@SH@@,${SH:Q}," ${PREFIX}/bin/cpuflags

.include <bsd.port.mk>

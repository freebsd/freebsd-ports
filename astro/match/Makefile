# ex:ts=8
# New ports collection makefile for:	match
# Date created:			Dec 17, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	match
PORTVERSION=	0.8
CATEGORIES=	astro
MASTER_SITES=	http://spiff.rit.edu/match/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for matching star lists

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/apply_match bin/match bin/project_coords

.include <bsd.port.mk>

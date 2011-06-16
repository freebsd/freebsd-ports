# New ports collection makefile for: jgraph
# Date created:		6 August 1999
# Whom:			wolman@cs.washington.edu
#
# $FreeBSD$
#

PORTNAME=	jgraph
PORTVERSION=	8.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://cs.utk.edu/pub/plank/jgraph/  \
		http://www.cs.washington.edu/homes/wolman/
DISTFILES=	${PORTNAME}.shar.Z

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2011-08-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program that generates postscript graphs

NO_LATEST_LINK=	yes
EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=	-c
EXTRACT_AFTER_ARGS=	| sh

NO_WRKSUBDIR=	yes
MAN1=		jgraph.1
MAKEFILE=	makefile

.include <bsd.port.mk>

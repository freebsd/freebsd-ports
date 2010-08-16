# New ports collection makefile for:	fpc-rsvg
# Date created:		2010-04-22
# Whom:			Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-rsvg

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to librsvg2 library

USE_FPC=	gtk2

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/^/lib/}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBRSVG2	"Install librsvg2 library"	on

.include "${MASTERDIR}/Makefile"

# New ports collection Makefile for:	tkhylafax
# Date created:		Sun Jun  8 11:51:21 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	tkhylafax
PORTVERSION=	3.2b
PORTREVISION=	2
CATEGORIES=	comms tk
MASTER_SITES=	ftp://ftp.hylafax.org/contrib/tkhylafax/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tcl/tk interface to Sam Leffler's fax package

USE_GHOSTSCRIPT_RUN=	yes
USE_TK_RUN=	yes

RUN_DEPENDS=	sendfax:${PORTSDIR}/comms/hylafax \
		gv:${PORTSDIR}/print/gv

WRKSRC=		${WRKDIR}/tkhylafax
MAN1=		tkhylafax.1

.include <bsd.port.mk>

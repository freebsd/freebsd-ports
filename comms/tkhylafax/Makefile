# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	tkhylafax
PORTVERSION=	3.2b
PORTREVISION=	5
CATEGORIES=	comms tk
MASTER_SITES=	ftp://ftp.hylafax.org/contrib/tkhylafax/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/tk interface to Sam Leffler's fax package

RUN_DEPENDS=	sendfax:${PORTSDIR}/comms/hylafax \
		gv:${PORTSDIR}/print/gv

USE_GHOSTSCRIPT_RUN=	yes
USE_TK_RUN=	84

WRKSRC=		${WRKDIR}/tkhylafax
MAN1=		tkhylafax.1

NO_STAGE=	yes
.include <bsd.port.mk>

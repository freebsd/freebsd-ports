# New ports collection makefile for:	tkgate
# Date created:				28 May 1999
# Whom:					Jeffery Hansen <hansen@cmu.edu>
#
# $FreeBSD$
#

PORTNAME=		tkgate
PORTVERSION=		1.6i
PORTREVISION=	1
CATEGORIES=		cad
MASTER_SITES=		ftp://gadoid.ices.cmu.edu/pub/tkgate/
EXTRACT_SUFX=		.tgz

MAINTAINER=		hansen@cmu.edu
COMMENT=	A Tcl/Tk based digital circuit editor and simulator

LIB_DEPENDS=		tk83.1:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=		tclsh8.3:${PORTSDIR}/lang/tcl83

GNU_CONFIGURE=		yes
USE_BISON=		yes
USE_X_PREFIX=   	yes

.include <bsd.port.mk>

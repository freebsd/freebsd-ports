# New ports collection makefile for:	autoconf
# Version required:     2.10
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.7 1996/04/01 05:09:13 asami Exp $
#

DISTNAME=       autoconf-2.10
CATEGORIES=	devel
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${PREFIX}/bin/gm4

.include <bsd.port.mk>

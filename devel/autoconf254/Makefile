# New ports collection makefile for:	autoconf
# Version required:     2.12
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.9 1996/11/18 10:22:14 asami Exp $
#

DISTNAME=       autoconf-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${PREFIX}/bin/gm4

.include <bsd.port.mk>

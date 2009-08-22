# New ports collection makefile for:	rrdman
# Date created:		2007-06-07
# Whom:			Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	rrdman
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/rrfw/${PORTNAME}/${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Apply Holt-Winters prediction parameters to RRD data

BUILD_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	YES
USE_PERL5=	YES
PLIST_FILES=	bin/rrd_hwreapply
MAN1=		rrd_hwreapply.1

.include <bsd.port.mk>

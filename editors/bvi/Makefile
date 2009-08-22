# New ports collection makefile for:	bvi
# Date created:				05 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	bvi
PORTVERSION=	1.3.2
CATEGORIES=	editors
MASTER_SITES=	SF
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	vd@FreeBSD.org
COMMENT=	A vi-like binary file (hex)editor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}

MAN1=		bvi.1 bmore.1
MLINKS=		bvi.1 bview.1 \
		bvi.1 bvedit.1

.include <bsd.port.mk>

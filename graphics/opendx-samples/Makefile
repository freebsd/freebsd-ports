# New ports collection makefile for:	opendx-samples
# Date created:		06 Oct 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opendx-samples
PORTVERSION=	4.0.8
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/
DISTNAME=	dxsamples-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SHELL=/bin/sh

# XXX
# someone with some knowledge of Java should make this work
post-configure:
	@touch ${WRKSRC}/java/samples/samples.jar

.include <bsd.port.mk>

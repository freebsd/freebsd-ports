# New ports collection makefile for:	opendx-samples
# Version required:	4.0.7
# Date created:		06 Oct 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	dxsamples-4.0.7
PKGNAME=	opendx-samples-4.0.7
CATEGORIES=	graphics math
MASTER_SITES=	http://opendx.npaci.edu/source/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SHELL=/bin/sh

# XXX
# someone with some knowledge of Java should make this work
post-configure:
	@touch ${WRKSRC}/java/samples/samples.jar

.include <bsd.port.mk>

# New ports collection makefile for:   generate
# Date created:        24 August 2006
# Whom:                D'Arcy J.M. Cain <darcy@druid.net>
#
# $FreeBSD$
#

PORTNAME=	generate
PORTVERSION=	2.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@druid.net
COMMENT=	Simple text pre-processor

USE_GMAKE=	yes
MAN1=		generate.1

PLIST_FILES=	bin/generate bin/rgenerate

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS *=,CFLAGS +=,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

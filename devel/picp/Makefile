# New ports collection makefile for:    picp
# Date created:         25 October 2002
# Whom:                 Bruce M Simpson <bms@spc.org>
#
# $FreeBSD$
#

PORTNAME=	picp
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://bofh.stabilis.ru/
DISTNAME=	${PORTNAME}_fbsd
EXTRACT_SUFX=	.tgz

MAINTAINER=	bms@spc.org
COMMENT=	Driver for the Microchip Picstart Plus development programmer

USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,CC=,CC?=,' -e 's,-O2,,' \
		-e 's,CFLAGS=,CFLAGS+=,' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/picp ${PREFIX}/bin

.include <bsd.port.mk>

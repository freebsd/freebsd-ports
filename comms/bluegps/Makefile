# Created by: dirkx@webweaving.org
# $FreeBSD$

PORTNAME=	bluegps-linux
PORTVERSION=	2.0
CATEGORIES=	comms
MASTER_SITES=	http://www.harbaum.org/till/bluegps/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dirkx@webweaving.org
COMMENT=	Command line tool to download datalogs from the Royaltek RBT-3000 bluetooth GPS receiver

MAN1=		bluegps.1
PLIST_FILES=	bin/bluegps

post-patch:
	@${REINPLACE_CMD} -e '/^CC=/d' ${WRKSRC}/Makefile

.include <bsd.port.mk>

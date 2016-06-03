# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	sim6811
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	sim
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motorola 6811 simulator

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_WRKSUBDIR=	yes

ALL_TARGET=	sim

PLIST_FILES=	bin/sim6811 man/man1/sim6811.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC =|CC ?=| ; \
		 s|^CFLAGS =|#CFLAGS =| ; \
		 s|-O2|| ; \
		 s|-o sim |-o sim6811 |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sim6811 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/sim6811.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	ibp
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://wwwhome.cs.utwente.nl/~ptdeboer/ham/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	A little program for monitoring amateur radio beacons

USES=		imake
USE_XORG=	x11

PLIST_FILES=	bin/ibp
MAN1=		ibp.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/ibp ${PREFIX}/bin/
	${INSTALL_MAN}	${WRKSRC}/ibp.1 ${MANPREFIX}/man/man1/ibp.1

.include <bsd.port.mk>

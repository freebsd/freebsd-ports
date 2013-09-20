# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	osdmixer
PORTVERSION=	0.9
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Displays audio volume with an OSD

LIB_DEPENDS=	xosd.4:${PORTSDIR}/misc/xosd

NO_STAGE=	yes
PLIST_FILES=	bin/osdmixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osdmixer ${PREFIX}/bin

.include <bsd.port.mk>

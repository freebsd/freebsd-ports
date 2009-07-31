# New ports collection makefile for:	osdmixer
# Date Created:				20 Mar 2007
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	osdmixer
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Displays audio volume with an OSD

BUILD_DEPENDS=	xosd-config:${PORTSDIR}/misc/xosd

PLIST_FILES=	bin/osdmixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osdmixer ${PREFIX}/bin

.include <bsd.port.mk>

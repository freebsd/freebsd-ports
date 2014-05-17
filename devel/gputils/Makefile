# Created by: Samuel Tardieu <sam@rfc1149.net>
# $FreeBSD$

PORTNAME=	gputils
PORTVERSION=	1.3.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Utilities for Microchip PIC microcontrollers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gplink-[0-9]*
GNU_CONFIGURE=	yes
USES=		gmake
CONFIGURE_ARGS= --disable-dependency-tracking --disable-html-doc

.include <bsd.port.mk>

# Created by: Samuel Tardieu <sam@rfc1149.net>
# $FreeBSD$

PORTNAME=	gputils
DISTVERSION=	1.4.2-1
CATEGORIES=	devel
MASTER_SITES=	SF/gputils/gputils/${PORTVERSION:R}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Utilities for Microchip PIC microcontrollers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gplink-[0-9]*
GNU_CONFIGURE=	yes
USES=		bison gmake
CONFIGURE_ARGS= --disable-dependency-tracking --disable-html-doc
WRKSRC=		${WRKDIR}/gputils-${PORTVERSION:R}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.35:textproc/flex
CONFIGURE_ARGS+=LEX=${LOCALBASE}/bin/flex
.endif

.include <bsd.port.mk>

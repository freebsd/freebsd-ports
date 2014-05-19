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

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.35:${PORTSDIR}/textproc/flex
CONFIGURE_ARGS+=LEX=${LOCALBASE}/bin/flex
.endif

post-patch:
	@${REINPLACE_CMD} 's/flex $$(AM_LFLAGS)/$$(LEXCOMPILE)/' \
		${WRKSRC}/gpasm/Makefile.in

.include <bsd.port.mk>

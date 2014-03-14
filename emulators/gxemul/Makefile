# Created by: Janni
# $FreeBSD$

PORTNAME=	gxemul
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://gxemul.sourceforge.net/src/ \
		http://gavare.se/gxemul/src/

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Instruction-level machine emulator

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

HAS_CONFIGURE=	yes
ALL_TARGET=	build
MAKE_JOBS_UNSAFE=	yes

MAN1=		gxemul.1
PORTDOCS=	*
PLIST_FILES=	bin/gxemul

USE_GCC=	yes

# svgalib installs vga.h, which conflicts with gxemul when building with
# a virtual VGA adaptor.
CONFLICTS=	svgalib-[0-9]*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
.else
CONFIGURE_ARGS+=--disable-x
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|/usr/X11R6|${LOCALBASE}|g; \
		 s|-O[0-9]?||g; \
		 s|-f[a-zA-Z-]+||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/gxemul.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${MKDIR} -p ${DOCSDIR}/components
	${MKDIR} -p ${DOCSDIR}/machines
	${INSTALL_DATA} ${WRKSRC}/doc/components/* ${DOCSDIR}/components
	${INSTALL_DATA} ${WRKSRC}/doc/machines/* ${DOCSDIR}/machines
	${INSTALL_DATA} `find ${WRKSRC}/doc/ -type f -depth 1` ${DOCSDIR}
.endif

.include <bsd.port.mk>

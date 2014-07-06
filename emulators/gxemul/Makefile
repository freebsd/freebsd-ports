# Created by: Janni
# $FreeBSD$

PORTNAME=	gxemul
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://gxemul.sourceforge.net/src/ \
		http://gavare.se/gxemul/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instruction-level machine emulator

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

HAS_CONFIGURE=	yes
ALL_TARGET=	build
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/gxemul \
		man/man1/gxemul.1.gz

USE_GCC=	yes

# svgalib installs vga.h, which conflicts with gxemul when building with
# a virtual VGA adaptor.
CONFLICTS=	svgalib-[0-9]*

X11_USE=	xorg=x11
X11_CONFIGURE_OFF=--disable-x

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|/usr/X11R6|${LOCALBASE}|g; \
		 s|-O[0-9]?||g; \
		 s|-f[a-zA-Z-]+||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/gxemul.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}/components \
		${STAGEDIR}${DOCSDIR}/machines
	${INSTALL_DATA} ${WRKSRC}/doc/components/* ${STAGEDIR}${DOCSDIR}/components
	${INSTALL_DATA} ${WRKSRC}/doc/machines/* ${STAGEDIR}${DOCSDIR}/machines
	${INSTALL_DATA} `find ${WRKSRC}/doc/ -type f -depth 1` ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

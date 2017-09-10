# Created by: Janni
# $FreeBSD$

PORTNAME=	gxemul
PORTVERSION=	0.6.0.1
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://gxemul.sourceforge.net/src/ \
		http://gavare.se/gxemul/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Instruction-level machine emulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-unittests
ALL_TARGET=	build
MAKE_JOBS_UNSAFE=	yes

# svgalib installs vga.h, which conflicts with gxemul when building with
# a virtual VGA adaptor.
CONFLICTS=	svgalib-[0-9]*

PORTDOCS=	*
PLIST_FILES=	bin/gxemul man/man1/gxemul.1.gz

OPTIONS_DEFINE=		DOCS X11
OPTIONS_DEFAULT=	X11

X11_USE=		xorg=x11
X11_CONFIGURE_OFF=	--disable-x

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|/usr/X11R6|${LOCALBASE}|g; \
		 /CXXFLAGS=/s|-O[0-9]?||g; \
		 /CXXFLAGS=/s|-f[a-zA-Z-]+||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gxemul.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

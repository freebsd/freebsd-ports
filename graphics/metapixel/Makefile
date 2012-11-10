# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	1.0.2
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/schani/metapixel/files/ \
		http://mirror.roe.ch/dist/metapixel/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Photomosaic generator

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		gif:${PORTSDIR}/graphics/giflib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		xcb:${PORTSDIR}/x11/libxcb

USE_GMAKE=	yes
USE_XORG=	ice sm x11 xau xdmcp
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	$$(libpng-config --I_opts) -I${LOCALBASE}/include -I.
LDFLAGS+=	$$(libpng-config --L_opts) -L${LOCALBASE}/lib

MAN1=		metapixel.1
PORTDOCS=	README NEWS
PORTEXAMPLES=	metapixelrc
PLIST_FILES=	bin/metapixel bin/metapixel-convert bin/metapixel-imagesize \
		bin/metapixel-prepare bin/metapixel-sizesort

.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKSRC}/getopt.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-convert ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel-imagesize ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-prepare ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-sizesort ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/metapixel.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

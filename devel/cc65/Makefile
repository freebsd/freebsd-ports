# Created by: Tim Vanderhoek <hoek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cc65
PORTVERSION=	2.18
PORTREVISION=	1
DISTVERSIONPREFIX=	V
CATEGORIES=	devel

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Cross-compiler for 6502-based systems

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake perl5 shebangfix
USE_PERL5=	build
USE_GITHUB=	yes

MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS=	samplesdir=${EXAMPLESDIR} infodir=${PREFIX}/${INFO_PATH}/cc65
ALL_TARGET=	all

SHEBANG_FILES=	util/ca65html

OPTIONS_DEFINE=	DOCS EXAMPLES INFO
OPTIONS_DEFAULT=	DOCS EXAMPLES INFO

DOCS_BUILD_DEPENDS=	linuxdoc:textproc/linuxdoc-tools
DOCS_ALL_TARGET=	html
INFO_BUILD_DEPENDS=	linuxdoc:textproc/linuxdoc-tools
INFO_INFO=	cc65/apple2 cc65/apple2enh cc65/ar65 cc65/atari \
		cc65/atari2600 cc65/atari5200 cc65/atmos cc65/c128 cc65/c16 \
		cc65/c64 cc65/ca65 cc65/cbm510 cc65/cbm610 cc65/cc65-intern \
		cc65/cc65 cc65/chrcvt65 cc65/cl65 cc65/co65 cc65/coding \
		cc65/creativision cc65/customizing cc65/da65 cc65/debugging \
		cc65/dio cc65/funcref cc65/gamate cc65/geos cc65/grc65 \
		cc65/index cc65/intro cc65/ld65 cc65/library cc65/lynx \
		cc65/nes cc65/od65 cc65/osi cc65/pce cc65/pet cc65/plus4 \
		cc65/sim65 cc65/smc cc65/sp65 cc65/supervision cc65/telestrat \
		cc65/tgi cc65/using-make cc65/vic20
INFO_USES=	makeinfo
INFO_ALL_TARGET=	info

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		'/gcc/s|^CC|#CC| ; \
		/-O2/s|^CFLAGS|#CFLAGS|'

post-install:
.for b in ar65 ca65 cc65 chrcvt65 cl65 co65 da65 grc65 ld65 od65 sim65 sp65
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${b}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

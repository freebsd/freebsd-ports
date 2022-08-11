PORTNAME=	jzintv
PORTVERSION=	1.0.20200712
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://spatula-city.org/~im14u2c/intv/dl/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^1.0.//1}-src

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Portable Intellivision(TM) Emulator

LICENSE=	GPLv2

USES=		alias compiler:c++11-lang dos2unix gmake sdl xorg zip
USE_XORG=	x11 xau xdmcp
USE_SDL=	sdl2

DOS2UNIX_GLOB=	*.[ch]
MAKE_ENV+=	LFLAGS="${LDFLAGS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/^1.0.//1}-src
BUILD_WRKSRC=	${WRKSRC}/src

OPTIONS_DEFINE=	TOOLS DOCS EXAMPLES
OPTIONS_SUB=	yes
TOOLS_DESC=	Install additional tools

TOOLS=	as1600 bin2luigi bin2rom cgc_update crc32 dasm0256 dasm1600 dis1600 \
	frombit frombit_r fromhex gms2rom imvtogif imvtoppm intvname luigi2bin \
	lzo_embed rom_merge rom_metadata rom2bin rom2luigi show_grom split_rom \
	tobit tobit_f tobit_r tohex

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} '/DEFAULT_ROM_PATH/s|/usr/local/share/jzintv|${DATADIR}|' ${BUILD_WRKSRC}/config.h
	@${CP} ${FILESDIR}/Makefile.freebsd_sdl2 ${BUILD_WRKSRC}/Makefile.freebsd_sdl2
	@${LN} -sf ${BUILD_WRKSRC}/Makefile.freebsd_sdl2 ${BUILD_WRKSRC}/Makefile

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/rom

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/rom
	${INSTALL_DATA} ${WRKSRC}/rom/*.rom ${STAGEDIR}${DATADIR}/rom/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/jzintv ${STAGEDIR}${PREFIX}/bin/jzintv
.for tool in ${TOOLS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${tool} ${STAGEDIR}${PREFIX}/bin/jzintv-${tool}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/doc
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/doc)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

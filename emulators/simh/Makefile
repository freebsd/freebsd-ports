# Created by: jraynard
# $FreeBSD$

PORTNAME=	simh
PORTVERSION=	3.9.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
DISTNAME=	${PORTNAME}v${PORTVERSION:R:S/.//}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others

NO_WRKSUBDIR=	yes

USES=		gmake dos2unix zip
DOS2UNIX_FILES=	makefile VAX/vax_sysdev.c
MAKE_ENV=	GCC="${CC}" CFLAGS_O="${CFLAGS}" USE_NETWORK=1
MAKEFILE=	makefile

SUB_FILES=	pkg-message

BIN_FILES=	altair altairz80 gri h316 hp2100 i1401 i1620 i7094 ibm1130 \
		id16 id32 lgp nova pdp1 pdp10 pdp11 pdp15 pdp4 pdp7 pdp8 pdp9 \
		s3 sds swtp6800mp-a swtp6800mp-a2 vax vax780

PORTDOCS=	0readme_${PORTVERSION:R:S/.//}.txt 0readme_ethernet.txt
PLIST_FILES=	${BIN_FILES:S/^/bin\//g} bin/simh-eclipse %%DATADIR%%/ka655x.bin

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${MKDIR} ${WRKSRC}/BIN

post-patch:
	@${REINPLACE_CMD} -e \
		'/shell ldconfig/s|^|#| ; \
		 /-O2/s| = | ?= |' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/VAX/vax_sysdev.c

do-install:
	(cd ${WRKSRC}/BIN && ${INSTALL_PROGRAM} ${BIN_FILES} \
		${STAGEDIR}${PREFIX}/bin)
# eclipse conflicts with java/eclipse, install it as simh-eclipse
	${INSTALL_PROGRAM} ${WRKSRC}/BIN/eclipse \
		${STAGEDIR}${PREFIX}/bin/simh-eclipse
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/VAX/ka655x.bin ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

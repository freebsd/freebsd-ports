# Created by: jraynard
# $FreeBSD$

PORTNAME=	simh
PORTVERSION=	3.9.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/sources/
DISTNAME=	${PORTNAME}v${PORTVERSION:R:S/.//}-${PORTVERSION:E}

MAINTAINER=	bob@eager.cx
COMMENT=	Emulates classic DEC, HP, GRI, IBM, Altair, SDS, Honeywell, and others

NO_WRKSUBDIR=	yes

USES=		gmake dos2unix zip
DOS2UNIX_FILES=	makefile VAX/vax_sysdev.c
MAKE_ENV=	GCC="${CC}" CFLAGS_O="${CFLAGS}" USE_NETWORK=1
MAKEFILE=	makefile

SUB_FILES=	pkg-message

PORTDOCS=	0readme_${PORTVERSION:R:S/.//}.txt 0readme_ethernet.txt

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${MKDIR} ${WRKSRC}/BIN

post-patch:
	@${REINPLACE_CMD} -e \
		'/shell ldconfig/s|^|#| ; \
		 /-O2/s| = | ?= |' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/VAX/vax_sysdev.c

post-build:
# eclipse conflicts with java/eclipse, install it as simh-eclipse
	@${MV} ${WRKSRC}/BIN/eclipse ${WRKSRC}/BIN/simh-eclipse

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/BIN/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/VAX/ka655x.bin ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

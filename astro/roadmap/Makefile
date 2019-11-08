# Created by: Nick Esborn <nick@netdot.net>
# $FreeBSD$

PORTNAME=	roadmap
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	astro geography
MASTER_SITES=	SF/${PORTNAME}/RoadMap/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector-based GPS moving map

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

MAKE_JOBS_UNSAFE=	yes

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20
MAKE_ARGS=	INSTALLDIR="${PREFIX}" CC="${CC}" CXX="${CXX}"

SUB_FILES=	pkg-message

PORTDOCS=	${DOCS} README
PLIST_FILES=	${BINS:S,^,bin/,} ${GUI_BINS:S,^,bin/,} \
		${GUI_BINS:S,^gtk,bin/,} ${SCRIPTS:S,^,bin/,} \
		man/man1/roadgps.1.gz man/man1/roadmap.1.gz \
		${DATA:S,^,%%DATADIR%%/,}

BINS=		dumpmap buildmap buildmap_osm buildplace buildus
GUI_BINS=	gtkroadmap gtkroadgps
SCRIPTS=	rdmcompare rdmdownload rdmgendcwmaps rdmgenmaps \
		rdmgenshpmaps rdmgenstatemaps
MANS=		roadgps.1 roadmap.1
DATA=		drivers preferences roadmap.popup roadmap.screenobjects \
		session sprites
DOCS=		Bugs ChangeLog Coding Configuration Developer-Guide \
		Installation Map-Building Map-Designing Map-Format \
		OpenStreetMap Platforms Quickstart Status ToDo Usage

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-O ||g ; \
		 s|/usr/include|${LOCALBASE}/include|g ; \
		 s|/usr/local/include|${LOCALBASE}/include|g ; \
		 s|/usr/local/lib|${LOCALBASE}/lib|g' ${WRKSRC}/src/options.mk
	@${ECHO_CMD} 'CFLAGS=${CFLAGS}' > ${WRKSRC}/src/overrides.mk
	@${ECHO_CMD} 'LDFLAGS=${LDFLAGS}' >> ${WRKSRC}/src/overrides.mk
	@${ECHO_CMD} 'LIBS=${LIBS}' >> ${WRKSRC}/src/overrides.mk

do-install:
.for _BIN in ${BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${_BIN} ${STAGEDIR}${PREFIX}/bin/${_BIN}
.endfor
.for _GUI_BIN in ${GUI_BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gtk2/${_GUI_BIN} ${STAGEDIR}${PREFIX}/bin/${_GUI_BIN}
	${LN} -sf ${_GUI_BIN} ${STAGEDIR}${PREFIX}/bin/${_GUI_BIN:S,^gtk,,}
.endfor
.for _SCRIPT in ${SCRIPTS}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${_SCRIPT} ${STAGEDIR}${PREFIX}/bin/${_SCRIPT}
.endfor
.for _MAN in ${MANS}
	${INSTALL_MAN} ${INSTALL_WRKSRC}/${_MAN} ${STAGEDIR}${MANPREFIX}/man/man1/${_MAN}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for _DATA in ${DATA}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${_DATA} ${STAGEDIR}${DATADIR}/${_DATA}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README
.for _DOC in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_DOC} ${STAGEDIR}${DOCSDIR}/${_DOC}
.endfor

.include <bsd.port.mk>

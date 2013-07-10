# Created by: Nick Esborn <nick@netdot.net>
# $FreeBSD$

PORTNAME=	roadmap
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	astro geography
MASTER_SITES=	SF/${PORTNAME}/RoadMap/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector-based GPS moving map

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

MAKE_JOBS_UNSAFE=	yes

USES=		gmake
USE_GNOME=	gtk20
MAKE_ARGS=	INSTALLDIR="${PREFIX}" CC="${CC}" CXX="${CXX}"

SUB_FILES=	pkg-message

MAN1=		roadgps.1 roadmap.1
PORTDOCS=	${DOCS} README
PLIST_FILES=	${BINS:S,^,bin/,} ${GUI_BINS:S,^,bin/,} \
		${GUI_BINS:S,^gtk,bin/,} ${SCRIPTS:S,^,bin/,} \
		${DATA:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

BINS=		dumpmap buildmap buildmap_osm buildplace buildus
GUI_BINS=	gtkroadmap gtkroadgps
SCRIPTS=	rdmcompare rdmdownload rdmgendcwmaps rdmgenmaps \
		rdmgenshpmaps rdmgenstatemaps
DATA=		drivers preferences roadmap.popup roadmap.screenobjects \
		session sprites
DOCS=		Bugs ChangeLog Coding Configuration Developer-Guide \
		Installation Map-Building Map-Designing Map-Format \
		OpenStreetMap Platforms Quickstart Status ToDo Usage

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-O ||g ; \
		 s|/usr/include|${LOCALBASE}/include|g ; \
		 s|/usr/local/include|${LOCALBASE}/include|g ; \
		 s|/usr/local/lib|${LOCALBASE}/lib|g' ${WRKSRC}/src/options.mk

do-install:
.for _BIN in ${BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${_BIN} ${PREFIX}/bin/${_BIN}
.endfor
.for _GUI_BIN in ${GUI_BINS}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/gtk2/${_GUI_BIN} ${PREFIX}/bin/${_GUI_BIN}
	${LN} -sf ${_GUI_BIN} ${PREFIX}/bin/${_GUI_BIN:S,^gtk,,}
.endfor
.for _SCRIPT in ${SCRIPTS}
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${_SCRIPT} ${PREFIX}/bin/${_SCRIPT}
.endfor
.for _MAN in ${MAN1}
	${INSTALL_MAN} ${INSTALL_WRKSRC}/${_MAN} ${MANPREFIX}/man/man1/${_MAN}
.endfor
	@${MKDIR} ${DATADIR}
.for _DATA in ${DATA}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${_DATA} ${DATADIR}/${_DATA}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.for _DOC in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${_DOC} ${DOCSDIR}/${_DOC}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

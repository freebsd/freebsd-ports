# Created by: Rick van der Zwet <rick@wzoeterwoude.net>
# $FreeBSD$

PORTNAME=	maude
PORTVERSION=	2.7.1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.illinois.edu/w/images/d/d8/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	High-performance reflective language

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libbdd.so:science/buddy \
		libtecla.so:devel/libtecla \
		libgmp.so:math/gmp \
		libsigsegv.so:devel/libsigsegv

USES=		alias autoreconf bison ncurses

WRKSRC=		${WRKDIR}/maude-${PORTVERSION}

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${NCURSESINC} -I${LOCALBASE}/include
LDFLAGS+=	-L${NCURSESLIB} -L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${DATADIR}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		DOCS FULL_MAUDE CVC4
OPTIONS_DEFAULT=	FULL_MAUDE CVC4
FULL_MAUDE_DESC=	Install full-maude
CVC4_DESC=		Enable SMT support via CVC4

CVC4_LIB_DEPENDS=	libcvc4.so:math/cvc4
CVC4_CONFIGURE_WITH=	cvc4

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULL_MAUDE}
MASTER_SITES+=	http://maude.cs.illinois.edu/w/images/c/ca/:fm
FULL_MAUDE=	full-maude.maude
FULL_MAUDE_DIST=	Full-Maude-${PORTVERSION}.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FULL_MAUDE_DIST}:fm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_DEPENDS+=	${LOCALBASE}/bin/unzip:archivers/unzip
PLIST_SUB+=	FULL_MAUDE=""
PLIST_SUB+=	FULL_MAUDE_VER="${FULL_MAUDE_VER}"
.else
PLIST_SUB+=	FULL_MAUDE="@comment "
.endif

post-extract-FULL_MAUDE-on:
	${UNZIP_CMD} ${DISTDIR}/${FULL_MAUDE_DIST} ${FULL_MAUDE} -d ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Mixfix/global.hh
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|g' \
		${WRKSRC}/configure.ac

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-FULL_MAUDE-on:
	${INSTALL_DATA} ${WRKDIR}/${FULL_MAUDE} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

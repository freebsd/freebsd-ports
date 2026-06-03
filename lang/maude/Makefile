PORTNAME=	maude
PORTVERSION=	2.7.1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.illinois.edu/w/images/d/d8/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance reflective language
WWW=		https://maude.cs.uiuc.edu/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libbdd.so:science/buddy \
		libtecla.so:devel/libtecla \
		libgmp.so:math/gmp \
		libsigsegv.so:devel/libsigsegv

USES=		autoreconf bison compiler:c++11-lang localbase:ldflags \
		ncurses
USE_CXXSTD=	c++14

WRKSRC=		${WRKDIR}/maude-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		DOCS FULL_MAUDE CVC4
OPTIONS_DEFAULT=	FULL_MAUDE #CVC4
FULL_MAUDE_DESC=	Install full-maude
CVC4_DESC=		Enable SMT support via CVC4

CVC4_LIB_DEPENDS=	libcvc5.so:math/cvc5
CVC4_CONFIGURE_WITH=	cvc4
CVC4_BROKEN=		maude uses cvc4 which has been succeeded by cvc5

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

.include <bsd.port.pre.mk>

.if ${NCURSESLIB} != /usr/lib
CPPFLAGS+=	-I${NCURSESINC}
LDFLAGS+=	-L${NCURSESLIB}
.endif

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

.include <bsd.port.post.mk>

# Created by: Rick van der Zwet <rick@wzoeterwoude.net>
# $FreeBSD$

PORTNAME=	maude
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/versions/${PORTVERSION}/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance reflective language

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libbdd.so:science/buddy \
		libtecla.so:devel/libtecla \
		libgmp.so:math/gmp \
		libsigsegv.so:devel/libsigsegv

USES=		autoreconf bison
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${DATADIR}
MAKE_JOBS_UNSAFE=	yes

FULL_MAUDE_VER=	26b

OPTIONS_DEFINE=	DOCS FULL_MAUDE
OPTIONS_DEFAULT=	FULL_MAUDE
FULL_MAUDE_DESC=	Install full-maude${FULL_MAUDE_VER}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Mixfix-lexerAux
.endif

.if ${PORT_OPTIONS:MFULL_MAUDE}
MASTER_SITES+=	http://maude.lcc.uma.es/FullMaude/FM${FULL_MAUDE_VER}/:fm
FULL_MAUDE=	full-maude${FULL_MAUDE_VER}.maude
FULL_MAUDE_DIST=	${FULL_MAUDE}.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FULL_MAUDE_DIST}:fm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_DEPENDS+=	${LOCALBASE}/bin/unzip:archivers/unzip
PLIST_SUB+=	FULL_MAUDE=""
PLIST_SUB+=	FULL_MAUDE_VER="${FULL_MAUDE_VER}"
.else
PLIST_SUB+=	FULL_MAUDE="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MFULL_MAUDE}
	${UNZIP_CMD} ${DISTDIR}/${FULL_MAUDE_DIST} ${FULL_MAUDE} -d ${WRKDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Mixfix/global.hh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MFULL_MAUDE}
	${INSTALL_DATA} ${WRKDIR}/${FULL_MAUDE} ${STAGEDIR}${DATADIR}
.endif

.include <bsd.port.mk>

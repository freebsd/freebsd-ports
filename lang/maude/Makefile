# Created by: Rick van der Zwet <rick@wzoeterwoude.net>
# $FreeBSD$

PORTNAME=	maude
PORTVERSION=	2.6
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/versions/${PORTVERSION}/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance reflective language

LIB_DEPENDS=	libbdd.so:${PORTSDIR}/science/buddy \
		libtecla.so:${PORTSDIR}/devel/libtecla \
		libgmp.so:${PORTSDIR}/math/gmp \
		libsigsegv.so:${PORTSDIR}/devel/libsigsegv

USES=		bison
USE_AUTOTOOLS=	aclocal autoheader automake
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${DATADIR}

FULL_MAUDE_VER=	26b

OPTIONS_DEFINE=	FULL_MAUDE
OPTIONS_DEFAULT=	FULL_MAUDE
FULL_MAUDE_DESC=	Install full-maude${FULL_MAUDE_VER}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFULL_MAUDE}
MASTER_SITES+=	http://maude.lcc.uma.es/FullMaude/FM${FULL_MAUDE_VER}/:fm
FULL_MAUDE=	full-maude${FULL_MAUDE_VER}.maude
FULL_MAUDE_DIST=	${FULL_MAUDE}.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FULL_MAUDE_DIST}:fm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_DEPENDS+=	${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
PLIST_SUB+=	FULL_MAUDE=""
PLIST_SUB+=	FULL_MAUDE_VER="${FULL_MAUDE_VER}"
.else
PLIST_SUB+=	FULL_MAUDE="@comment "
.endif

.if ${PORT_OPTIONS:MFULL_MAUDE}
post-extract:
	${UNZIP_CMD} ${DISTDIR}/${FULL_MAUDE_DIST} ${FULL_MAUDE} -d ${WRKDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Mixfix/global.hh

.if ${PORT_OPTIONS:MFULL_MAUDE}
post-install:
	${INSTALL_DATA} ${WRKDIR}/${FULL_MAUDE} ${DATADIR}
.endif

.include <bsd.port.mk>

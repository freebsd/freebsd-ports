# Created by: Rick van der Zwet <rick@wzoeterwoude.net>
# $FreeBSD$

PORTNAME=	maude
PORTVERSION=	2.6
CATEGORIES=	lang
MASTER_SITES=	http://maude.cs.uiuc.edu/versions/${PORTVERSION}/
DISTNAME=	Maude-${PORTVERSION}

MAINTAINER=	joemann@beefree.free.de
COMMENT=	A high-performance reflective language

LIB_DEPENDS=	bdd:${PORTSDIR}/science/buddy \
		tecla:${PORTSDIR}/devel/libtecla \
		gmp:${PORTSDIR}/math/gmp \
		sigsegv:${PORTSDIR}/devel/libsigsegv

USES=		bison
USE_AUTOTOOLS=	aclocal autoheader automake
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir=${DATADIR}

FULL_MAUDE_VER=	26b
OPTIONS=	FULL_MAUDE "Install full-maude${FULL_MAUDE_VER}" On

.include <bsd.port.options.mk>

.if defined(WITH_FULL_MAUDE)
MASTER_SITES+=	http://maude.lcc.uma.es/FullMaude/FM${FULL_MAUDE_VER}/:fm
FULL_MAUDE=	full-maude${FULL_MAUDE_VER}.maude
FULL_MAUDE_DIST=	${FULL_MAUDE}.zip
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FULL_MAUDE_DIST}:fm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_DEPENDS+=	${LOCALBASE}/unzip:${PORTSDIR}/archivers/unzip
PLIST_SUB+=	FULL_MAUDE=""
PLIST_SUB+=	FULL_MAUDE_VER="${FULL_MAUDE_VER}"
.else
PLIST_SUB+=	FULL_MAUDE="@comment "
.endif

.if defined(WITH_FULL_MAUDE)
post-extract:
	${UNZIP_CMD} ${DISTDIR}/${FULL_MAUDE_DIST} ${FULL_MAUDE} -d ${WRKDIR}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Mixfix/global.hh

.if defined(WITH_FULL_MAUDE)
post-install:
	${INSTALL_DATA} ${WRKDIR}/${FULL_MAUDE} ${DATADIR}
.endif

.include <bsd.port.mk>

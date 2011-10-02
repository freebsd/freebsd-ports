# Ports collection makefile for: LibChipCard
# Date created:                  19 January 2003
# Whom:                          Martin Preuss <martin@libchipcard.de>
#
# $FreeBSD$
#

PORTNAME=	libchipcard
PORTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=02&release=26&file=01&dummy=/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	A library for easy access to chipcards

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite \
		gwenhywfar.63:${PORTSDIR}/devel/gwenhywfar

USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_OPENSSL=	yes

OPTIONS=	APIDOC "Full API documentation (requires Doxygen)" off \
		MEMDEBUG "Enable memory debugger statistic" off

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" aq_distrib_name="FreeBSD"
CONFIGURE_ARGS+=--enable-release="yes" \
		--with-pcsc-includes=${LOCALBASE}/include \
		--with-pcsc-libs=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"
USE_LDCONFIG=	yes

GWEN_SHLIB_VER=	60

.include <bsd.port.options.mk>

.if defined(WITH_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz
CONFIGURE_ARGS+=--enable-full-doc
PORTDOCS=	apidoc
.endif

.if defined(WITH_MEMDEBUG)
CONFIGURE_ARGS+=--enable-memtrace
.endif

post-patch:
	${REINPLACE_CMD} -e 's|aq_endian\" ==|aq_endian\" =|g' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|find chipcard|find libchipcard5|' \
		${WRKSRC}/Makefile.in

post-build:
.if defined(WITH_APIDOC)
	@cd ${WRKSRC} && ${GMAKE} srcdoc
.endif

post-install:
.if defined(WITH_APIDOC)
	${MKDIR} ${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${DOCSDIR}/apidoc
.endif

.include <bsd.port.mk>

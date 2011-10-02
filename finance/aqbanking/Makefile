# New ports collection makefile for:	aqbanking
# Date created:		June 2005
# Whom:                 Sam Lawrance <lawrance@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqbanking
PORTVERSION=	5.0.16
CATEGORIES=	finance
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=03&release=87&file=01&dummy=/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Online banking interface and financial data framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gwenhywfar.63:${PORTSDIR}/devel/gwenhywfar \
		gmp.10:${PORTSDIR}/math/gmp

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack pkgconfig

OPTIONS=	APIDOC "Full API documentation (requires Doxygen)" off \
		KTOBLZCHECK "KtoBlzCheck support" off \
		PAYPAL "Build PayPal backend (separate license)" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	AQB_SHLIB_VER="${AQB_SHLIB_VER}" \
		GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"
USE_LDCONFIG=	yes

AQB_SHLIB_VER=	33
GWEN_SHLIB_VER=	60

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz
CONFIGURE_ARGS+=--enable-full-doc
PORTDOCS=	apidoc
.endif

.if defined(WITH_KTOBLZCHECK) || exists(${LOCALBASE}/lib/libktoblzcheck.so)
LIB_DEPENDS+=	ktoblzcheck:${PORTSDIR}/finance/ktoblzcheck
.endif

.if defined(WITH_PAYPAL)
CONFIGURE_ARGS+=--with-backends="aqhbci aqnone aqofxconnect aqpaypal"
PLIST_SUB+=	WITH_PAYPAL=""
.else
PLIST_SUB+=	WITH_PAYPAL="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|install-idataDATA install-iheaderHEADERS|install-iheaderHEADERS|' \
		${WRKSRC}/Makefile.in

post-build:
.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
	@cd ${WRKSRC} && ${GMAKE} srcdoc
.endif

post-install:
.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
	${MKDIR} ${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${DOCSDIR}/apidoc
.endif

.include <bsd.port.mk>

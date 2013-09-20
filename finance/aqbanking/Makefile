# $FreeBSD$

PORTNAME=	aqbanking
PORTVERSION=	5.0.25
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	http://www.aquamaniac.de/sites/download/download.php?package=03&release=95&file=01&dummy=/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	gwenhywfar:${PORTSDIR}/devel/gwenhywfar \
		gmp:${PORTSDIR}/math/gmp

OPTIONS_DEFINE=		DOXYGEN KTOBLZCHECK PAYPAL
OPTIONS_DEFAULT=	KTOBLZCHECK

KTOBLZCHECK_DESC=	Enable KtoBlzCheck support
PAYPAL_DESC=		Build PayPal backend (separate license)

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USES=	pathfix pkgconfig gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	AQB_SHLIB_VER="${AQB_SHLIB_VER}" \
		GWEN_SHLIB_VER="${GWEN_SHLIB_VER}"
USE_LDCONFIG=	yes

AQB_SHLIB_VER=	34
GWEN_SHLIB_VER=	60

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz
CONFIGURE_ARGS+=--enable-full-doc
.endif

.if ${PORT_OPTIONS:MKTOBLZCHECK} || exists(${LOCALBASE}/lib/libktoblzcheck.so)
LIB_DEPENDS+=	ktoblzcheck:${PORTSDIR}/finance/ktoblzcheck
.endif

.if ${PORT_OPTIONS:MPAYPAL}
CONFIGURE_ARGS+=--with-backends="aqhbci aqnone aqofxconnect aqpaypal"
PLIST_SUB+=	WITH_PAYPAL=""
.else
PLIST_SUB+=	WITH_PAYPAL="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|install-idataDATA install-iheaderHEADERS|install-iheaderHEADERS|' \
		${WRKSRC}/Makefile.in

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@cd ${WRKSRC} && ${GMAKE} srcdoc
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${DOCSDIR}/apidoc
	@${FIND} -P ${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -P -d ${DOCSDIR} -type d 2>/dev/null | \
		${SED} -ne 's,^${PREFIX}/,@dirrm ,p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>

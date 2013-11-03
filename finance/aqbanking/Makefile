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

LIB_DEPENDS=	libgwenhywfar.so:${PORTSDIR}/devel/gwenhywfar \
		libgmp.so:${PORTSDIR}/math/gmp

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USES=		pathfix pkgconfig gettext

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

OPTIONS_DEFINE=		DOXYGEN KTOBLZCHECK PAYPAL
OPTIONS_DEFAULT=	KTOBLZCHECK
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen \
			dot:${PORTSDIR}/graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

KTOBLZCHECK_DESC=	Enable KtoBlzCheck support

PAYPAL_DESC=		Build PayPal backend (separate license)
PAYPAL_CONFIGURE_ON=	--with-backends="aqhbci aqnone aqofxconnect aqpaypal"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKTOBLZCHECK} || exists(${LOCALBASE}/lib/libktoblzcheck.so)
LIB_DEPENDS+=	libktoblzcheck.so:${PORTSDIR}/finance/ktoblzcheck
.endif

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	@cd ${WRKSRC} && ${GMAKE} srcdoc
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}
	@${FIND} -P -d ${STAGEDIR}${DOCSDIR} -type d 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/|@dirrm |p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>

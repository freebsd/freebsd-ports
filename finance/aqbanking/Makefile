# $FreeBSD$

PORTNAME=	aqbanking
PORTVERSION=	6.2.9
CATEGORIES=	finance
MASTER_SITES=	https://www.aquamaniac.de/rdm/attachments/download/366/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Online banking interface and financial data framework

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
		libltdl.so:devel/libltdl \
		libgmp.so:math/gmp \
		libgnutls.so:security/gnutls

USES=		gettext gmake libtool localbase:ldflags pathfix pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes"
INSTALL_TARGET=	install-strip
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

AQB_SHLIB_VER=	44
PLIST_SUB=	AQB_SHLIB_VER="${AQB_SHLIB_VER}" \
		AQB_MAJ_MIN_VER="${PORTVERSION:R}"

OPTIONS_DEFINE=		DOCS DOXYGEN EBICS KTOBLZCHECK
OPTIONS_DEFAULT=	KTOBLZCHECK
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

EBICS_DESC=		Enable EBICS backend
EBICS_LIB_DEPENDS=	libxmlsec1.so:security/xmlsec1
EBICS_USES=		gnome
EBICS_USE=		GNOME=libxml2,libxslt
EBICS_CONFIGURE_OFF=	--with-backends="aqhbci aqofxconnect aqpaypal"

KTOBLZCHECK_DESC=	Enable KtoBlzCheck support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKTOBLZCHECK} || exists(${LOCALBASE}/lib/libktoblzcheck.so)
LIB_DEPENDS+=	libktoblzcheck.so:finance/ktoblzcheck
.endif

.if ${PORT_OPTIONS:MDOCS} && !${PORT_OPTIONS:MDOXYGEN}
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e \
	's|$$(top_builddir)/aqbanking6|$$(top_builddir)/*|g' \
	${WRKSRC}/configure

pre-configure-EBICS-on:
	@(if [ ! -e ${LOCALBASE}/libdata/pkgconfig/xmlsec1-gnutls.pc ] ; then \
	${ECHO_MSG} "(Re)Install security/xmlsec1 with the GNUTLS option ON" ; \
	exit 1; \
	fi)

post-build-DOXYGEN-on:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} srcdoc

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>

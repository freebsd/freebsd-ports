PORTNAME=	aqbanking
PORTVERSION=	6.6.0
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	https://www.aquamaniac.de/rdm/attachments/download/531/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Online banking interface and financial data framework
WWW=		https://www.aquamaniac.de/rdm/projects/aqbanking

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
		libgmp.so:math/gmp

USES=		gettext gmake libtool localbase:ldflags pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release="yes"
INSTALL_TARGET=	install-strip

_AQB_SHLIB_VER=	44
PLIST_SUB=	AQB_SHLIB_VER="${_AQB_SHLIB_VER}" \
		AQB_MAJ_MIN_VER="${PORTVERSION:R}" \
		AQB_MIN_PATCH_VER="${PORTVERSION:R:E}.${PORTVERSION:E}"

OPTIONS_DEFINE=		DOCS DOXYGEN EBICS
OPTIONS_DEFAULT=	EBICS
OPTIONS_SUB=		yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENABLE=	full-doc

EBICS_DESC=		Enable EBICS backend
EBICS_LIB_DEPENDS=	libltdl.so:devel/libltdl \
			libxmlsec1.so:security/xmlsec1
EBICS_USES=		gnome
EBICS_USE=		GNOME=libxml2,libxslt
EBICS_CONFIGURE_OFF=	--with-backends="aqgivve aqhbci aqofxconnect aqpaypal aqnone"

post-patch:
# No such aqbanking6 directory exists nor is ever created for
# aqbanking_symlinkdir, so use src/libs instead. This is really
# only needed for when the DOXYGEN option is enabled.
	@${REINPLACE_CMD} -e \
		's|$$(top_builddir)/aqbanking6|$$(top_builddir)/src/libs|g' \
		${WRKSRC}/configure

post-build-DOXYGEN-on:
	@cd ${WRKSRC} && ${SETENVI} ${MAKE_ENV} ${MAKE_CMD} srcdoc

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidoc
	cd ${WRKSRC}/apidoc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/apidoc
	@${FIND} -P ${STAGEDIR}${DOCSDIR}/apidoc -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>

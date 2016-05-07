# $FreeBSD$

PORTNAME=	libosmocore
PORTVERSION=	0.9.0
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmocore/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Common library for all Osmocom projects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite

USES=		alias autoreconf execinfo gmake libtool pathfix pkgconfig
PATHFIX_MAKEFILEIN=Makefile.am
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENV_OFF=ac_cv_path_DOXYGEN=false

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version

.include <bsd.port.mk>

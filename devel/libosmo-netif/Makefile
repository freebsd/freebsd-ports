# $FreeBSD$

PORTNAME=	libosmo-netif
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	http://git.osmocom.org/libosmo-netif/snapshot/ \
		http://chaosophia.net/downloads/osmocom/${PORTNAME}/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Library containing common/shared code regarding network interface

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		unfetchable

LIB_DEPENDS=	libosmocore.so:devel/libosmocore \
		libosmoabis.so:devel/libosmo-abis \
		libtalloc.so:devel/talloc

USES=		autoreconf libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PORTDOCS=	*

OPTIONS_DEFINE=	DOXYGEN DAHDI DOCS

DOXYGEN_DESC=	Build documentation
DAHDI_DESC=	Build DAHDI input driver

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CONFIGURE_ENV_OFF=ac_cv_path_DOXYGEN=false

DAHDI_BUILD_DEPENDS=	${LOCALBASE}/include/dahdi/user.h:misc/dahdi
DAHDI_CPPFLAGS=		-I${LOCALBASE}/include

post-patch:
	${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/.tarball-version
	@${REINPLACE_CMD} -e 's,__bswap_,__bswap,' \
		${WRKSRC}/examples/rs232-write.c

.include <bsd.port.mk>

PORTNAME=	openzwave
PORTVERSION=	1.4.3254
CATEGORIES=	comms

MAINTAINER=	johan@stromnet.se
COMMENT=	Open-source interface to Z-Wave networks

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/license/license.txt

USES=		gmake iconv pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	OpenZWave
GH_PROJECT=	open-zwave
GH_TAGNAME=	f339aa6

CFLAGS+=	-Wno-error
MAKE_ARGS=	VERSION_REV=${PORTVERSION:E} LIBDIR=${WRKSRC}

CONFLICTS_INSTALL=	openzwave-devel # bin/MinOZW

OPTIONS_DEFINE=	DOCS DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_MAKE_ARGS=	ENABLE_DOCS=1 docdir=${DOCSDIR}
DOXYGEN_PORTDOCS=	*

post-install:
	${MV} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DATADIR}
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/lib/libopenzwave.so.1.4
	${STRIP_CMD} ${STAGEDIR}${LOCALBASE}/bin/MinOZW

post-install-DOXYGEN-on:
	${RM} ${STAGEDIR}${DOCSDIR}/Doxyfile.in

.include <bsd.port.mk>

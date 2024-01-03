PORTNAME=	urt
PORTVERSION=	3.1b1
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	https://BSDforge.com/projects/source/graphics/utah-raster/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Toolkit and library for raster image processing
WWW=		https://www.cs.utah.edu/gdc/projects/urt/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/copyright

BROKEN=		Unfetchable

LIB_DEPENDS=	libnetpbm.so:graphics/netpbm \
		libtiff.so:graphics/tiff

USES=		gmake tar:xz xorg

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_WRKSUBDIR=	yes

CFLAGS+=	-I${LOCALBASE}/include/netpbm
USE_XORG=	x11 xext
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	config/urt
MAKEFILE=	makefile
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}
ALL_TARGET=	# none
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librle.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/img
	@(cd ${WRKSRC}/img && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/img)

.include <bsd.port.post.mk>

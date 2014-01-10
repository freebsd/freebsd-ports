# Created by: cfs@ing.puc.cl (original)
# $FreeBSD$

PORTNAME=	urt
PORTVERSION=	3.1b1
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.iastate.edu/pub/utah-raster/
DISTNAME=	urt
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar.Z urt-img.tar.Z

PATCH_SITES=	http://www.funet.fi/pub/graphics/packages/urt/rel2/
PATCHFILES=	urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit and library for raster image processing

LIB_DEPENDS=	libnetpbm.so:${PORTSDIR}/graphics/netpbm

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_WRKSUBDIR=	yes

USE_XORG=	x11 xext
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	config/urt
USES=		gmake
MAKEFILE=	makefile
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}
ALL_TARGET=	# none
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/img
	@(cd ${WRKSRC}/img && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/img)
.endif

.include <bsd.port.mk>

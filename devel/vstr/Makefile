# Created by: Robert Schlotterbeck <robert@rs.tarrant.tx.us>
# $FreeBSD$

PORTNAME=	vstr
PORTVERSION=	1.0.15
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.and.org/vstr/${PORTVERSION}/ \
		http://www.and.org/vstr/latest/ \
		http://ionut.tetcu.info/FreeBSd/ports/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose string library for C

LICENSE=	LGPL21

USES=		gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${WRKSRC}/Documentation && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_fLAGS} ${MAKEFILE} ${MAKE_ARGS} install-man3

regression-test:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.mk>

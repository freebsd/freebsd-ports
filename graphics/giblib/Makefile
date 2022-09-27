PORTNAME=	giblib
PORTVERSION=	1.2.4
PORTREVISION=	13
CATEGORIES=	graphics devel
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Utility library that includes a wrapper for imlib2
WWW=		https://web.archive.org/web/20090904063608/http://linuxbrit.co.uk/giblib

DEPRECATED=	Last release in 2004, abandoned upstream, not used, website disappeared
EXPIRATION_DATE=2022-11-27

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		pathfix pkgconfig libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	docsdir=${DOCSDIR}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgiblib.so

.include <bsd.port.mk>

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

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip install-man
TEST_TARGET=	check  # XXX: 4 of 231 tests fail

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

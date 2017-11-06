# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cptutils
PORTVERSION=	1.68
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics
MASTER_SITES=	http://soliton.vm.bytemark.co.uk/pub/jjg/src/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert and manipulate colour gradients

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gengetopt:devel/gengetopt \
		gperf:devel/gperf \
		docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libjansson.so:devel/jansson \
		libpng.so:graphics/png

BROKEN_powerpc64=	fails to build: grd5read.c: \#pragma GCC diagnostic not allowed inside functions

USE_GITHUB=	yes
GH_ACCOUNT=	jjgreen

USES=		autoreconf bison gmake iconv localbase python shebangfix
SHEBANG_FILES=	src/gradient-convert/gradient-convert.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
USE_GNOME=	libxml2 libxslt

PORTDOCS=	CHANGELOG CREDITS README.md

OPTIONS_DEFINE=		DOCS TEST

TEST_CONFIGURE_ENABLE=	tests
TEST_BUILD_DEPENDS=	bash:shells/bash \
			xml2:textproc/xml2 \
			xml:textproc/xmlstarlet
TEST_LIB_DEPENDS=	libcunit.so:devel/cunit
TEST_TEST_TARGET=	test unit

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>

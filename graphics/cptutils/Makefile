PORTNAME=	cptutils
PORTVERSION=	1.82
CATEGORIES=	graphics
MASTER_SITES=	http://soliton.vm.bytemark.co.uk/pub/jjg/src/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Convert and manipulate colour gradients
WWW=		http://soliton.vm.bytemark.co.uk/pub/jjg/en/code/cptutils/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gengetopt:devel/gengetopt \
		gperf:devel/gperf \
		docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libjansson.so:devel/jansson \
		libpng.so:graphics/png

USES=		autoreconf bison gmake gnome iconv localbase python shebangfix
SHEBANG_FILES=	src/gradient-convert/gradient-convert.py
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
USE_GNOME=	libxml2 libxslt

PORTDOCS=	CHANGELOG.md CREDITS.md README.md

OPTIONS_DEFINE=		DOCS TEST

TEST_CONFIGURE_ENABLE=	tests
TEST_BUILD_DEPENDS=	bash:shells/bash
TEST_LIB_DEPENDS=	libcunit.so:devel/cunit
TEST_TEST_TARGET=	test

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>

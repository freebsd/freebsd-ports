PORTNAME=	unadf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	archivers

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extracts files from .adf-files used by Amiga emulators
WWW=		http://lclevy.free.fr/adflib/unadf.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	bash>0:shells/bash

USES=		autoreconf cpe libtool pathfix pkgconfig shebangfix
CPE_VENDOR=	unadf_project
USE_GITHUB=	yes
GH_ACCOUNT=	lclevy
GH_PROJECT=	ADFlib
USE_LDCONFIG=	yes

SHEBANG_FILES=	examples/tests/test_examples_basic.sh

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

DOCSDIR=	${PREFIX}/share/doc/adflib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

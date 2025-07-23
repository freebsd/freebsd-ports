PORTNAME=	unadf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.2
CATEGORIES=	archivers

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Extracts files from .adf-files used by Amiga emulators
WWW=		http://lclevy.free.fr/adflib/unadf.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cpe libtool pkgconfig
CPE_VENDOR=	unadf_project
USE_GITHUB=	yes
GH_ACCOUNT=	adflib
GH_PROJECT=	ADFlib
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

DOCSDIR=	${PREFIX}/share/doc/adflib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

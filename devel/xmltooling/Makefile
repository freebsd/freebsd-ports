# Created by: Janos Mohacsi
# $FreeBSD$

PORTNAME=	xmltooling
PORTVERSION=	3.0.4
PORTREVISION=	3
CATEGORIES=	devel security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/3.0.1/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Low level XML support for SAML

LICENSE=	APACHE20

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblog4shib.so:devel/log4shib \
		libxerces-c.so:textproc/xerces-c3 \
		libxml-security-c.so:security/apache-xml-security-c

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-dependency-tracking --disable-doxygen-doc --with-xmlsec
USES=		gmake libtool pkgconfig tar:bzip2 ssl autoreconf
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	openssl_LIBS="-L${OPENSSLLIB} -lcrypto"  openssl_CFLAGS=-I${OPENSSLBASE}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.am

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>

# Created by: Janos Mohacsi
# $FreeBSD$

PORTNAME=	xmltooling
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/2.6.0/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Low level XML support for SAML

LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblog4shib.so:devel/log4shib \
		libxerces-c.so.3:textproc/xerces-c3 \
		libxml-security-c.so:security/apache-xml-security-c

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} --with-curl=${LOCALBASE} --disable-doxygen-doc
USES=		gmake libtool pkgconfig tar:bzip2
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

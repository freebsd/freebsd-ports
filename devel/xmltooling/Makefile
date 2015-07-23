# Created by: Janos Mohacsi
# $FreeBSD$

PORTNAME=	xmltooling
PORTVERSION=	1.5.5
CATEGORIES=	devel security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/2.5.5/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Low level XML support for SAML

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		liblog4shib.so:${PORTSDIR}/devel/log4shib \
		libxerces-c.so.3:${PORTSDIR}/textproc/xerces-c3 \
		libxml-security-c.so:${PORTSDIR}/security/apache-xml-security-c

BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} --with-curl=${LOCALBASE} --disable-doxygen-doc
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>

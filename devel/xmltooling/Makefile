# Created by: Janos Mohacsi
# $FreeBSD$

PORTNAME=	xmltooling
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://shibboleth.net/downloads/c++-opensaml/2.5.3/

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Low level XML support for SAML

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		log4shib.1:${PORTSDIR}/devel/log4shib \
		xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
		xml-security-c.17:${PORTSDIR}/security/apache-xml-security-c
	
BUILD_DEPENDS=	boost-libs>=0:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} --with-curl=${LOCALBASE} --disable-doxygen-doc
USE_GCC=	any
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^pkgdocdir.*=.*,pkgdocdir = ${DOCSDIR},' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s,doc ,,' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>

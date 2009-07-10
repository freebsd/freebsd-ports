# New ports collection makefile for:	xmltooling
# Date created:				12 September 2008
# Whom:					Janos Mohacsi
#
# $FreeBSD$
#

PORTNAME=	xmltooling
DISTVERSION=	1.2
CATEGORIES=	devel security
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/2.2/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Low level XML support for SAML

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		log4shib.1:${PORTSDIR}/devel/log4shib \
		xerces-c.28:${PORTSDIR}/textproc/xerces-c2-devel \
		xml-security-c.14:${PORTSDIR}/security/apache-xml-security-c

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} --with-curl=${LOCALBASE} --disable-doxygen-doc
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

.include <bsd.port.mk>

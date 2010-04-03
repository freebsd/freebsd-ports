# New ports collection makefile for:	xmltooling
# Date created:				12 September 2008
# Whom:					Janos Mohacsi
#
# $FreeBSD$
#

PORTNAME=	xmltooling
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://shibboleth.internet2.edu/downloads/opensaml/cpp/2.3/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Low level XML support for SAML

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl \
		log4shib.1:${PORTSDIR}/devel/log4shib \
		xerces-c.28:${PORTSDIR}/textproc/xerces-c2-devel \
		xml-security-c.14:${PORTSDIR}/security/apache-xml-security-c

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-log4shib=${LOCALBASE} --with-openssl=${OPENSSLBASE} --with-curl=${LOCALBASE} --disable-doxygen-doc
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

# New ports collection makefile for:   opendnssec
# Date created:        28 December 2009
# Whom:                Jaap Akkerhuis <jaap@NLnetLabs.nl>
#
# $FreeBSD$
#

PORTNAME=	opendnssec
PORTVERSION=	1.0.0
CATEGORIES=	dns
MASTER_SITES=	http://www.opendnssec.org/files/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}rc1

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

BUILD_DEPENDS+=	ldns>=1.6.3:${PORTSDIR}/dns/ldns
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/Ft/Xml/__init__.py:${PORTSDIR}/textproc/py-4suite-xml
BUILD_DEPENDS+=	rubygem-dnsruby>=${DNSRUBY_VER}:${PORTSDIR}/dns/rubygem-dnsruby
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS+=	ldns:${PORTSDIR}/dns/ldns
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_PYTHON=	2.4+
USE_RUBY=	yes
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's/ Ft.Xml.XPath//' ${WRKSRC}/signer/configure

.include <bsd.port.mk>

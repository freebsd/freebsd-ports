# New ports collection makefile for:   opendnssec
# Date created:        28 December 2009
# Whom:                Jaap Akkerhuis <jaap@NLnetLabs.nl>
#
# $FreeBSD$
#

PORTNAME=	opendnssec
PORTVERSION=	1.1.1
CATEGORIES=	dns
MASTER_SITES=	http://www.opendnssec.org/files/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Tool suite for maintaining DNSSEC

BUILD_DEPENDS=	ldns>=1.6.4:${PORTSDIR}/dns/ldns \
		${PYTHON_SITELIBDIR}/Ft/Xml/__init__.py:${PORTSDIR}/textproc/py-4suite-xml \
		rubygem-dnsruby>=1.43:${PORTSDIR}/dns/rubygem-dnsruby
LIB_DEPENDS=	ldns:${PORTSDIR}/dns/ldns \
		sqlite3:${PORTSDIR}/databases/sqlite3

GNU_CONFIGURE=	yes
USE_GNOME=	libxml2
USE_PERL5=	yes
USE_PYTHON=	2.4+
USE_RUBY=	yes
USE_LDCONFIG=	yes

MAN1=		ods-auditor.1 ods-hsmspeed.1 ods-hsmutil.1 ods-kaspcheck.1 \
		ods-ksmutil.1
MAN5=		ods-timing.5
MAN7=		opendnssec.7
MAN8=		ods-control.8 ods-enforcerd.8 ods-signer.8 ods-signerd.8

pre-configure:
	@${REINPLACE_CMD} -e 's/ Ft.Xml.XPath//' ${WRKSRC}/signer/configure

.include <bsd.port.mk>

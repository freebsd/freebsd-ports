# New ports collection makefile for:    dnsmax-perl
# Date created:                         Sun Jan 23 20:27:00 CST 2005
# Whom:                                 Dan Smith <dan@algenta.com>
#
# $FreeBSD$
#

PORTNAME=	dnsmax-perl
PORTVERSION=	1.0.1
CATEGORIES=	dns
MASTER_SITES=	SF/dynamicdns/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}

MAINTAINER=	dan@algenta.com
COMMENT=	DNSMax-perl is a perl DNS update client for the REST DNSMax protocol

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Crypt/SSLeay.pm:${PORTSDIR}/security/p5-Crypt-SSLeay \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/dnsmax-perl
PORTDOCS=	LICENSE INSTALL README

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/dnsmax.pl ${PREFIX}/bin/dnsmax-perl
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

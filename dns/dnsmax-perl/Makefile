# Created by: Dan Smith <dan@algenta.com>
# $FreeBSD$

PORTNAME=	dnsmax-perl
PORTVERSION=	1.0.1
CATEGORIES=	dns
MASTER_SITES=	SF/dynamicdns/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}

MAINTAINER=	dan@algenta.com
COMMENT=	DNSMax-perl is a perl DNS update client for the REST DNSMax protocol

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USES=		perl5 zip

PLIST_FILES=	bin/dnsmax-perl
PORTDOCS=	LICENSE INSTALL README

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/dnsmax.pl ${PREFIX}/bin/dnsmax-perl
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

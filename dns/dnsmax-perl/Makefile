# Created by: Dan Smith <dan@algenta.com>
# $FreeBSD$

PORTNAME=	dnsmax-perl
PORTVERSION=	1.0.1
CATEGORIES=	dns
MASTER_SITES=	SF/dynamicdns/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME:tl}-${PORTVERSION:S/.p/-pre/:S/.b/-beta/}

MAINTAINER=	dan@algenta.com
COMMENT=	DNSMax-perl is a perl DNS update client for the REST DNSMax protocol

BUILD_DEPENDS=	p5-Crypt-SSLeay>=0:security/p5-Crypt-SSLeay \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-libwww>=0:www/p5-libwww

NO_BUILD=	yes
USES=		perl5 zip shebangfix

SHEBANG_FILES=	dnsmax.pl
PLIST_FILES=	bin/dnsmax-perl
PORTDOCS=	LICENSE INSTALL README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/dnsmax.pl ${STAGEDIR}${PREFIX}/bin/dnsmax-perl
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	ftpsync
# Date created:		31 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpsync
PORTVERSION=	1.3.03
PORTEPOCH=	1
CATEGORIES=	ftp
MASTER_SITES=	http://ftpsync.sourceforge.net/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Synchronizes a local and a remote FTP directory trees

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/${PORTNAME}.pl
PORTDOCS=	README

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>

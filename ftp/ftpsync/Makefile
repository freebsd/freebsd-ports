# New ports collection makefile for:	ftpsync
# Date created:		31 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpsync
PORTVERSION=	1.2.33
CATEGORIES=	ftp
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Synchronizes a local and a remote FTP directory trees

RUN_DEPENDS=	p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww

NO_BUILD=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/${PORTNAME}.pl

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		 requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin/

.include <bsd.port.post.mk>

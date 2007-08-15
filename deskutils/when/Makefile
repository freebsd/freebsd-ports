# New ports collection makefile for:	when
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	when
PORTVERSION=	1.1.2
CATEGORIES=	deskutils
MASTER_SITES=	CENKES
#http://www.lightandmatter.com/when/when.tar.gz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A very simple personal calendar

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>

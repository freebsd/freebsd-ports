# New ports collection makefile for:	when
# Date created:		1 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	when
PORTVERSION=	1.0.28
CATEGORIES=	deskutils
MASTER_SITES=	http://bsd1.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/

MAINTAINER=	infofarmer@gmail.com
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

# ex:ts=8
# New ports collection makefile for:   ucpp
# Date created:                Feb 16, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ucpp
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.di.ens.fr/~pornin/ucpp/

MAINTAINER=	ijliao@FreeBSD.org

MAN1=	ucpp.1

post-patch:
	@${PERL} -pi -e "s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

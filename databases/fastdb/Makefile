# ex:ts=8
# New ports collection makefile for:	fastdb
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fastdb
PORTVERSION=	2.16
CATEGORIES=	databases
MASTER_SITES=	http://www.ispras.ru/~knizhnik/

MAINTAINER=	ijliao@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
MAKEFILE=	makefile

INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/makefile

.include <bsd.port.mk>

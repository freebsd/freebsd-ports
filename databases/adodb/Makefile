# New ports collection makefile for: adodb
# Date created:		4 May 2001
# Whom:			abgoeree@uwnet.nl
#
# $FreeBSD$
#

PORTNAME=	adodb
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	http://phplens.com/lens/dl/
DISTNAME=	${PORTNAME}112
EXTRACT_SUFX=	.tgz

MAINTAINER=	abgoeree@uwnet.nl

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

do-install:
	${MKDIR} ${PREFIX}/share/doc/apache/php/adodb
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/share/doc/apache/php/adodb

.include <bsd.port.mk>

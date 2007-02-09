# New ports collection makefile for:	pear
# Date created:			25 Nov 2005
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pear
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ale

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PEAR framework for PHP

USE_BZIP2=	yes
NO_BUILD=	yes

WANT_PHP_CLI=	yes
USE_PHP=	pcre xml

PEARDIR=	${PREFIX}/share/pear

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/go-pear

do-install:
	@${LOCALBASE}/bin/php -q ${WRKSRC}/go-pear

.include <bsd.port.mk>

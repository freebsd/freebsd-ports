# New ports collection makefile for:	German phone codes
# Date created:         1997-12-30
# Whom:                 wosch
#
# $FreeBSD$
#

PORTNAME=	phone
PORTVERSION=	1.0
CATEGORIES=	german misc
MASTER_SITES=	http://wolfram.schneider.org/src/
DISTNAME=	avon-1996
EXTRACT_SUFX=	.gz

MAINTAINER=	wosch@FreeBSD.org
COMMENT=	German phone code / Deutsche Telefonvorwahl (AVON)

PLIST_FILES=	share/misc/de.phone
NO_WRKSUBDIR=	YES
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# None
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/de.phone
NO_BUILD=	YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/de.phone ${PREFIX}/share/misc

.include <bsd.port.mk>

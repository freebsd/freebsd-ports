# New ports collection makefile for:	hattrickorganizer
# Date Created:		17 Jan 2005
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	hattrickorganizer
PORTVERSION=	1.32
CATEGORIES=	games java
MASTER_SITES=	http://www.wow-auctions.net/ho/download/
DISTNAME=	ho_${PORTVERSION:S/.//g}

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A management tool for Hattrick.org written in Java

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

do-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/share/${PORTNAME}
	@${CP} -r ${FILESDIR}/hattrickorganizer /${PREFIX}/bin/
	@${CHMOD} 755 /${PREFIX}/bin/hattrickorganizer

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

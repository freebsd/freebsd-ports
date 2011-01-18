# New ports collection makefile for:	checkheaders
# Date created:		August 18, 2010
# Whom:	      		bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	checkheaders
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Checks headers in C/C++ programs

USE_ZIP=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME}

LICENSE=	GPLv3

post-patch:
	@${REINPLACE_CMD} -e '/^CXX.*=/d' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>

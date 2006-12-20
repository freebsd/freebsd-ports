# New ports collection makefile for:	id3lib
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	id3lib
PORTVERSION=	3.8.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kaeru@inigo-tech.com
COMMENT=	Library for manipulating ID3v1/v1.1 and ID3v2 tags

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-extract:
	@${RM} -rf ${WRKSRC}/zlib

.include <bsd.port.mk>

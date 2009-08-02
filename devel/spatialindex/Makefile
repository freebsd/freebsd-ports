# New ports collection makefile for:	spatialindex
# Date created:				15 June 2008
# Whom:					Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	spatialindex
PORTVERSION=	1.3.2
CATEGORIES=	devel
MASTER_SITES=	http://www.edu-linux.org/down/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A General Framework for Developing Spatial Indices

USE_AUTOTOOLS=	libtool:22:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|\(objformat=\).*|\1elf|' ${WRKSRC}/configure

.include <bsd.port.mk>

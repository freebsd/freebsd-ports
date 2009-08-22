# New ports collection makefile for:    zh-oto
# Date created:		8 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	oto
PORTVERSION=	0.5
CATEGORIES=	chinese print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Show you font info and add new 'name' and 'cmap' tables

USE_ICONV=	yes
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LIBS="-L${LOCALBASE}/lib -liconv"

post-patch:
	@${FIND} ${WRKSRC}/src/ -type f -print0 | \
	    ${XARGS} -0 ${REINPLACE_CMD} -e 's,stdint.h,inttypes.h,'

.include <bsd.port.mk>

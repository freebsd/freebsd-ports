# New ports collection makefile for:    zh-oto
# Date created:		8 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	oto
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	chinese print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	statue@freebsd.sinica.edu.tw
COMMENT=	Show you font info and add new 'name' and 'cmap' tables

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_GETOPT_LONG=yes
HAS_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LIBS="-L${LOCALBASE}/lib -liconv"

.include <bsd.port.pre.mk>
post-patch:
	@${FIND} ${WRKSRC}/src/ -name "*" | ${XARGS} ${REINPLACE_CMD} -e 's,stdint.h,inttypes.h,'
.include <bsd.port.post.mk>

# New ports collection makefile for:	libiptcdata
# Date created:				3rd December 2006
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiptcdata
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Library for manipulating IPTC metadata stored in image files

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile (UINT32_MAX not defined)
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/libiptcdata/Makefile.in

.include <bsd.port.post.mk>

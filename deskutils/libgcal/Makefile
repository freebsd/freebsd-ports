# New ports collection makefile for:	libgcal
# Date created:		2009-08-16
# Whom:			Troels Kofoed Jacobsen <tkjacobsen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libgcal
PORTVERSION=	0.9.2
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	tkjacobsen@gmail.com
COMMENT=	Library allowing communication with google calendar and contacts

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		iconv:${PORTSDIR}/converters/libiconv \
		xml2:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

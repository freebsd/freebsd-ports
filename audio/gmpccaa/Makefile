# New ports collection makefile for:	gmpccaa
# Date created:		Apr 4 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gmpccaa
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://download.qballcow.nl/programs/gmpc-0.13/Plugins/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Amazon cover art provider for gmpc

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		curl.4:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gmpc.pc:${PORTSDIR}/audio/gmpc
RUN_DEPEND=	gmpc:${PORTSDIR}/audio/gmpc

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

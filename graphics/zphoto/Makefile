# New ports collection makefile for:	zphoto
# Date created:				19 Jul 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	zphoto
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	Zooming photo album generator

LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming \
		Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		popt.0:${PORTSDIR}/devel/popt \
		aviplay.0:${PORTSDIR}/multimedia/avifile
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
	       	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ming \
		${PTHREAD_CFLAGS}"
USE_GMAKE=		yes
USE_XLIB=	yes

.include <bsd.port.mk>

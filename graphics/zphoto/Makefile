# New ports collection makefile for:	zphoto
# Date created:				19 Jul 2002
# Whom:					UMENO Takashi <umeno@rr.iij4u.or.jp>
#
# $FreeBSD$
#

PORTNAME=	zphoto
PORTVERSION=	0.2
CATEGORIES=	graphics www
MASTER_SITES=	http://namazu.org/~satoru/zphoto/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umeno@rr.iij4u.or.jp

#BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming \
		Imlib2.1:${PORTSDIR}/graphics/imlib2 \
		popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/ming"
USE_XLIB=	yes

.include <bsd.port.mk>

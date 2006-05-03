# New ports collection makefile for:	rio500
# Date created:		27 May 2000
# Whom:			Kazumasa Nishizawa <k_nishizawa@anet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	rio500
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	fortune@n.jpn.ph
COMMENT=	Utilities for Diamond Rio500

USE_GNOME=	glib12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath='/dev' \
		--with-deviceentry='urio0' \
		--with-id3support


.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,byteswap.h,sys/endian.h," \
		${WRKSRC}/lib/libfon.c \
		${WRKSRC}/lib/librio500.c
	${REINPLACE_CMD} -e "s,getopt.h,," ${WRKSRC}/include/Makefile.in

.include <bsd.port.post.mk>

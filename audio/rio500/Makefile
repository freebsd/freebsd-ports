# Created by: Kazumasa Nishizawa <k_nishizawa@anet.ne.jp>
# $FreeBSD$

PORTNAME=	rio500
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for Diamond Rio500

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	glib12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-devicepath='/dev' \
		--with-deviceentry='urio0' \
		--with-id3support

post-patch:
	${REINPLACE_CMD} -e "s,byteswap.h,sys/endian.h," \
		${WRKSRC}/lib/libfon.c \
		${WRKSRC}/lib/librio500.c
	${REINPLACE_CMD} -e "s,getopt.h,," ${WRKSRC}/include/Makefile.in

.include <bsd.port.mk>

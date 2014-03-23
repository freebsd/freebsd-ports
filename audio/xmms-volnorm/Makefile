# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	volnorm
PORTVERSION=	0.8.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Volume Normalizer plugin for XMMS

LICENSE=	GPLv2

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|tests||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^COMMON/s|-O2|@CFLAGS@|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Effect
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libnormvol.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Effect

.include <bsd.port.mk>

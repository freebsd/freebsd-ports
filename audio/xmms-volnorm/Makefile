# New ports collection makefile for:	xmms-volnorm
# Date created:				Fri Aug 17 12:17:23 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	volnorm
PORTVERSION=	0.8.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Volume Normalizer plugin for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk12
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Effect/libnormvol.so

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|tests||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^COMMON/s|-O2|@CFLAGS@|g' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/.libs/libnormvol.so ${PREFIX}/lib/xmms/Effect

.include <bsd.port.mk>

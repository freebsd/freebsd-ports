# New ports collection makefile for:  libmad
# Date created:        26 November 2003
# Whom:                Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	libmad
PORTVERSION=	0.15.1b
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.mars.org/pub/mpeg/
MASTER_SITE_SUBDIR=	mad

MAINTAINER=	asa@gascom.ru
COMMENT=	Libmad library (part of MAD project)

USE_INC_LIBTOOL_VER=	13
USE_GNOME=	pkgconfig
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--disable-debugging \
		--enable-sso
.if defined(WITH_SPEED)
CONFIGURE_ARGS+=	--enable-speed
.else
CONFIGURE_ARGS+=	--enable-accuracy
.endif

post-patch:
	@${SED} -e 's|%PREFIX%|${PREFIX}|g ; s|%VERSION%|${PORTVERSION}|g' \
		${FILESDIR}/mad.pc.in > ${WRKDIR}/mad.pc

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>

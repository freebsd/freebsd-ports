# New ports collection makefile for:	libmrproject
# Date created:				17 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmrproject
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library backend for MrProject project management application

LIB_DEPENDS=	gsf-1.9:${PORTSDIR}/devel/libgsf

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnometarget
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/libmrproject.sh > ${PREFIX}/etc/rc.d/000.libmrproject.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.libmrproject.sh

.include <bsd.port.mk>

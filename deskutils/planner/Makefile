# New ports collection makefile for:	MrProject
# Date created:				15 July 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrproject
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Project management application for Gnome 2

LIB_DEPENDS=	mrproject.0:${PORTSDIR}/deskutils/libmrproject

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui libgnomeprintui
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/mrproject.sh > ${PREFIX}/etc/rc.d/000.mrproject.sh
	@${CHMOD} 750 ${PREFIX}/etc/rc.d/000.mrproject.sh

.include <bsd.port.mk>

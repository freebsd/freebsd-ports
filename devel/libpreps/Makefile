# New ports collection makefile for:	libpreps
# Date created:		Fri Mar 19 14:27:30 EET 2004
# Whom:			shadow@psoft.net
#
# $FreeBSD$
#

PORTNAME=	libpreps
PORTVERSION=	1.6.6
CATEGORIES=	devel
MASTER_SITES=	http://webpages.charter.net/stuffle/linux/preps/
DIST_SUBDIR=	prep

MAINTAINER=	shadow@psoft.net
COMMENT=	Problem reporting system

LIB_DEPENDS=	pq.3:${PORTSDIR}/databases/postgresql7

CONFLICTS=	libpreps-1.9.*

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--with-pgsqldir=${LOCALBASE} --with-plpgsqldir=${LOCALBASE}

INSTALLS_SHLIB=	yes

.if defined(WITHOUT_SERVER)
CONFIGURE_ARGS+=--disable-server
PKGNAMESUFFIX=	-client
PLIST_SUB+=	SERVER="@comment "
.else
MAN1=		create_prepsdb.1 update_prepsdb.1
PLIST_SUB+=	SERVER=""
.endif

.include <bsd.port.mk>

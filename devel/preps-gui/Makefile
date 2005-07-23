# New ports collection makefile for:	preps-gui
# Date created:		Fri Mar 19 14:27:30 EET 2004
# Whom:			shadow@psoft.net
#
# $FreeBSD$
#

PORTNAME=	preps-gui
PORTVERSION=	1.8.1
CATEGORIES=	devel
MASTER_SITES=	http://webpages.charter.net/stuffle/linux/preps/
DISTNAME=	preps-${PORTVERSION}
DIST_SUBDIR=	prep

MAINTAINER=	shadow@psoft.net
COMMENT=	Problem reporting system

LIB_DEPENDS+=	preps-1.6.1:${PORTSDIR}/devel/libpreps

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12 gnomelibs
MAN1=		preps.1

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-pgsqldir=${LOCALBASE} \
			--with-plpgsqldir=${LOCALBASE} \
			--with-libprepsdir=${LOCALBASE}

.include <bsd.port.mk>

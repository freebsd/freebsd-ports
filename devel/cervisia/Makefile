# New ports collection Makefile for: cervisia
# Version required:	0.2.1
# Date created:         17 Nov 1999
# Whom:                 Will Andrews <andrews@technologist.com>
#
# $FreeBSD$

DISTNAME=	cervisia-0.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.kde.org/pub/kde/unstable/apps/utils/

MAINTAINER=	andrews@technologist.com

RUN_DEPENDS=	kwm:${PORTSDIR}/x11/kdebase11

USE_X_PREFIX=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--with-extra-includes="${LOCALBASE}/include" \
		--with-extra-libraries="${LOCALBASE}/lib"
CONFIGURE_ENV=	prefix="${LOCALBASE}" KDEDIR="${LOCALBASE}"

MAN1=		cervisia.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400012
BROKEN=		"Requires NEWGCC-compiled kde libs"
.endif

.include <bsd.port.post.mk>

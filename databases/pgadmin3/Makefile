# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR= pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

LIB_DEPENDS+=	wx_gtk2u_stc-2.5.3:${PORTSDIR}/x11-toolkits/wxgtk2-unicode-contrib-devel

USE_PGSQL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx=${X11BASE}\
		--with-wx-config=wxgtk2u-2.5-config
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Systems prior to FreeBSD 5.0 currently out of support
.endif

.include <bsd.port.post.mk>

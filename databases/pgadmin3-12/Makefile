# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR= pgadmin3/release/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx=${X11BASE}
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

POSTGRESQL_PORT?=	databases/postgresql-client

.include <bsd.port.pre.mk>

#.if ${OSVERSION} < 500000
LIB_DEPENDS+=	wx_gtk2_stc-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2-contrib
CONFIGURE_ARGS+=--with-wx-config=wxgtk2-2.4-config
#.else
#LIB_DEPENDS+=	wx_gtk2u_stc-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2-unicode-contrib
#CONFIGURE_ARGS+=--with-wx-config=wxgtk2u-2.4-config
#.endif

.include <bsd.port.post.mk>

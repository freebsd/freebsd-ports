# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR= pgadmin3/release/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT} \
		wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel \
		wx_gtk_stc.0:${PORTSDIR}/x11-toolkits/wxgtk-contrib

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx=${X11BASE}
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

POSTGRESQL_PORT?=	databases/postgresql-client

.include <bsd.port.mk>

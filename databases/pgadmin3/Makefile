# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.10.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

CONFLICTS=	pgadmin3-1.[12]*

MAKE_JOBS_SAFE=	yes
USE_GETTEXT=	yes
USE_PGSQL=	yes
IGNORE_WITH_PGSQL=	73 74
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-wx-version=${USE_WX}
USE_GNOME=	libxml2 libxslt
USE_WX=		2.8
WX_COMPS=	wx contrib
WX_CONF_ARGS=	relative
WX_UNICODE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/wx-config,/${WX_CONFIG:T},' ${WRKSRC}/configure

.include <bsd.port.mk>

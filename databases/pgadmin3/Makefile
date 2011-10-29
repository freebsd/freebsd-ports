# New ports collection makefile for:    pgadmin3
# Date created:                         November 4, 2003
# Whom:                                 Max Khon
#
# $FreeBSD$
#

PORTNAME=	pgadmin3
PORTVERSION=	1.14.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	pgadmin3/release/v${PORTVERSION}/src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

MAKE_JOBS_SAFE=	yes
USE_GETTEXT=	yes
USE_PGSQL=	yes
USE_GMAKE=	yes
IGNORE_WITH_PGSQL=	82 83
DIST_SUBDIR=	postgresql
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--with-wx-version=${USE_WX}
USE_GNOME=	libxml2 libxslt
USE_WX=		2.8
WX_COMPS=	wx contrib
WX_UNICODE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/wx-config,/${WX_CONFIG:T},' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/usr/bin/xterm,${LOCALBASE}/bin/xterm,' ${WRKSRC}/plugins.d/plugins.ini
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' ${WRKSRC}/pgadmin/ver_svn.sh

.include <bsd.port.mk>

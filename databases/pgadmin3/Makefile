# Created by: Max Khon
# $FreeBSD$

PORTNAME=	pgadmin3
PORTVERSION=	1.18.1
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	PGSQL
MASTER_SITE_SUBDIR=	pgadmin3/release/v${PORTVERSION}/src
DIST_SUBDIR=	postgresql

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	PostgreSQL database design and management system

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

IGNORE_WITH_PGSQL=	82 83

USES=		gettext gmake pgsql
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-version=${USE_WX} --enable-databasedesigner
USE_GNOME=	libxml2 libxslt
USE_WX=		2.8
WX_COMPS=	wx contrib
WX_UNICODE=	yes

PLIST_FILES=	bin/pgadmin3
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's,/wx-config,/${WX_CONFIG:T},' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/usr/bin/xterm,${LOCALBASE}/bin/xterm,' ${WRKSRC}/plugins.d/plugins.ini
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' ${WRKSRC}/pgadmin/ver_svn.sh

.include <bsd.port.mk>

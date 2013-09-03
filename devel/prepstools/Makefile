# Created by: jmelo@FreeBSD.org
# $FreeBSD$

PORTNAME=	prepstools
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://webpages.charter.net/stuffle/preps/download/files/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Problem reporting system

RUN_DEPENDS=	postgres:${PORTSDIR}/databases/postgresql${DEFAULT_PGSQL_VER}-server

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
USE_PGSQL=	yes
USES=		gmake pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gtk20 gconf2 glib20 libgnomeui

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pgsqldir=${LOCALBASE} --with-plpgsqldir=${LOCALBASE}

USE_LDCONFIG=	yes

.include <bsd.port.mk>

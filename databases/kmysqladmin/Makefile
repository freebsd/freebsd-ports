# Created by: Igor Leonenko <bananaz@bk.ru>
# $FreeBSD$

PORTNAME=	kmysqladmin
PORTVERSION=	0.7.2
PORTREVISION=	10
CATEGORIES=	databases
MASTER_SITES=	http://www.alwins-world.de/programs/download/kmysqladmin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical frontend for administration of MySQL servers

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_AUTOTOOLS=	libtool
USE_MYSQL=	yes
USE_QT_VER=	3
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql

.include <bsd.port.mk>

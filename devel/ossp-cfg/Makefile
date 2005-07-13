# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-cfg
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cfg
PORTVERSION=	0.9.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for parsing arbitrary C/C++-style configuration files

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

USE_LIBTOOL_VER=	15
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN3=		cfg.3

.include <bsd.port.mk>

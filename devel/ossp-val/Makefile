# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-val
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	val
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible name to value mapping library for C variables

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}

MAN1=	val-config.1
MAN3=	val.3

NOT_FOR_ARCHS=	alpha

.include <bsd.port.mk>

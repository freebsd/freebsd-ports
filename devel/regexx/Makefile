# ex:ts=8
# New ports collection makefile for:	regexx
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	regexx
PORTVERSION=	0.98.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete regular expressions C++ solution

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>

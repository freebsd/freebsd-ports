# ex:ts=8
# New ports collection makefile for:	regexx
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	regexx
PORTVERSION=	0.98.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Regexx is a complete regular expressions C++ solution

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>

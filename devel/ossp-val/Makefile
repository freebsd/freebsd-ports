# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-val
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	val
PORTVERSION=	0.9.2
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>

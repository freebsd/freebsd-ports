# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-mm
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	ex
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	me@davidyu.org
COMMENT=	OSSP ex is a small exception handling library for use in C

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>

# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ossp-mm
# Date created:		2003-01-31
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	ex
PORTVERSION=	1.0.2
PORTREVISION=	1
PORTEPOCH=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/ex/
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OSSP ex is a small exception handling library for use in C

USE_GMAKE=	yes
GNU_CONFIGURE=  yes
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB= yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" || ${ARCH} == "amd64"
BROKEN=		"Does not compile on alpha or amd64"
.endif

.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>

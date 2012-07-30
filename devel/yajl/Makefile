# New ports collection makefile for:	yajl
# Date created:		2010-03-29
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yajl
PORTVERSION=	2.0.4
CATEGORIES=	devel
MASTER_SITES=	http://github.com/lloyd/yajl/tarball/${GITREF}/
DISTNAME=	lloyd-${PORTNAME}-${GITREF}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A Portable JSON parsing and serialization library in ANSI C

FETCH_ARGS=	-Fpr
GITREF=		fee1ebe
PLIST_SUB=	VERSION=${PORTVERSION}

LICENSE=	BSD

USE_LDCONFIG=	yes
USE_CMAKE=	yes

.include <bsd.port.mk>

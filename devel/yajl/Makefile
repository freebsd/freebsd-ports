# New ports collection makefile for:	yajl
# Date created:		2010-03-29
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	yajl
PORTVERSION=	2.0.1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/bapt \
		http://files.etoilebsd.net/yajl/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	A Portable JSON parsing and serialization library in ANSI C

GITREF=		f4b2b1a
DISTNAME=	lloyd-${PORTNAME}-${PORTVERSION}-${GITREF}
WRKSRC=		${WRKDIR}/lloyd-${PORTNAME}-${GITREF}
PLIST_SUB=	VERSION=${PORTVERSION}

LICENSE=	BSD

USE_LDCONFIG=	yes
USE_CMAKE=	yes

.include <bsd.port.mk>

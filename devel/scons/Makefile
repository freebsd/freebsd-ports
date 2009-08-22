# New ports collection makefile for:	scons
# Date created:				16 December 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	scons
PORTVERSION=	1.2.0
PORTREVISION=	20090223
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}.d20090223
DISTNAME=	${PORTNAME}-${PORTVERSION}.d${PORTREVISION}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A build tool alternative to make

MAKE_JOBS_SAFE=  yes

.if !defined (NO_INSTALL_MANPAGES)
MAN1=		scons.1 sconsign.1 scons-time.1
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${PREFIX}/lib/scons-${PORTVERSION}.d${PORTREVISION}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.d${PORTREVISION}

PLIST_SUB=	SCONS_VER=${PORTVERSION}.d${PORTREVISION}

.include <bsd.port.mk>

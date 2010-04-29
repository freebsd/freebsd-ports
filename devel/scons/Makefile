# New ports collection makefile for:	scons
# Date created:				16 December 2001
# Whom:					Peter Haight <peterh@sapros.com>
#
# $FreeBSD$
#

PORTNAME=	scons
PORTVERSION=	1.3.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	paul@querna.org
COMMENT=	A build tool alternative to make

MAKE_JOBS_SAFE=	yes

.if !defined (NO_INSTALL_MANPAGES)
MAN1=		scons.1 sconsign.1 scons-time.1
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${PREFIX}/lib/scons-${PORTVERSION}

PLIST_SUB+=	SCONS_VER=${PORTVERSION}

.include <bsd.port.mk>

# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	scons
PORTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	gavin@16degrees.com.au
COMMENT=	A build tool alternative to make

RUN_DEPENDS+=	python2:${PORTSDIR}/lang/python2

.if !defined (NO_INSTALL_MANPAGES)
MAN1=		scons.1 sconsign.1 scons-time.1
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${PREFIX}/lib/scons-${PORTVERSION}

PLIST_SUB+=	SCONS_VER=${PORTVERSION}

USE_PYTHON=	-2.7

.include <bsd.port.pre.mk>

.if defined (NO_INSTALL_MANPAGES)
PYDISTUTILS_INSTALLARGS+=	--no-install-man
.endif

.include <bsd.port.post.mk>

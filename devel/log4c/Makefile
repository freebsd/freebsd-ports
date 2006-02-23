# ex:ts=8
# Ports collection makefile for:	log4c
# Date created:			Jul 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	log4c
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Logging for C Library

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>

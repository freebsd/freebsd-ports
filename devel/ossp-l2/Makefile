# New ports collection makefile for:	ossp-l2
# Date created:				2003-01-31
# Whom:					Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	l2
PORTVERSION=	0.9.11
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A C library for a flexible and sophisticated Unix logging facility

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=		l2-config.1 l2tool.1
MAN3=		l2.3

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>

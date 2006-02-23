# New ports collection makefile for:	ossp-cfg
# Date created:				2003-01-31
# Whom:					Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	cfg
PORTVERSION=	0.9.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A library for parsing arbitrary C/C++-style configuration files

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN3=		cfg.3

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>

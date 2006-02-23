# New ports collection makefile for:	ossp-val
# Date created:				2003-01-31
# Whom:					Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	val
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A flexible name to value mapping library for C variables

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}

MAN1=	val-config.1
MAN3=	val.3

NOT_FOR_ARCHS=	alpha

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>

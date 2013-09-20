# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	val
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible name to value mapping library for C variables

LIB_DEPENDS=	ex.10:${PORTSDIR}/devel/ossp-ex

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}

MAN1=	val-config.1
MAN3=	val.3

NOT_FOR_ARCHS=	alpha

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

NO_STAGE=	yes
.include <bsd.port.mk>

# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

PORTNAME=	al
PORTVERSION=	0.9.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Defines an abstract type of buffer that can move data without copying

LIB_DEPENDS=	libex.so:${PORTSDIR}/devel/ossp-ex

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ex=${LOCALBASE}
USE_LDCONFIG=	yes

check:	build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>

# New ports collection Makefile for:	onyx
# Date created:		15 May 2001
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	onyx
PORTVERSION=	4.2.1
CATEGORIES=	lang
MASTER_SITES=	http://www.canonware.com/download/onyx/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	cook:${PORTSDIR}/devel/cook
LIB_DEPENDS=	edit.5:${PORTSDIR}/devel/libedit

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libedit-prefix=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN1=		onyx.1 onyx_config.1

PLIST_SUB=	ONYX_VERSION=${PORTVERSION}

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} cook install)

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/onyx
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

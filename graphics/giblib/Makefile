# Ports collection makefile for:	giblib
# Date created:				12 Nov 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	giblib
PORTVERSION=	1.2.2
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	NO_DOC=yes
.endif

.include <bsd.port.mk>

# ports collection makefile for:	gigabase
# Date created:			15 August 2000
# Whom:				Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	gigabase
PORTVERSION=	2.56
CATEGORIES=	databases
MASTER_SITES=	http://www.ispras.ru/~knizhnik/

MAINTAINER=	ozz@FreeBSD.org.ru

WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --build=$(ARCH} --host=unknown-freebsd --target=${OSREL}

.include <bsd.port.mk>

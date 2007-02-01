# New ports collection makefile for: 	libmimedir
# Date created:                March 2004
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	libmimedir
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libmimedir

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for parsing RFC2425 MIME Directory Profile information

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_BISON=	yes
USE_LDCONFIG=	yes

INSTALLS_SHLIB=	yes

regression-test:
		cd ${WRKSRC} && ./test

.include <bsd.port.mk>

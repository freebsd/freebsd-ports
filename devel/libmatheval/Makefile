# New ports collection makefile for:	libmatheval
# Date created:				4 July 2004
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmatheval
PORTVERSION=	1.1.0
CATEGORIES=	devel math
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A library of procedures for evaluating mathematical functions

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	MAKEINFO="/usr/bin/makeinfo --no-split"
INSTALLS_SHLIB=	yes

INFO=		libmatheval

post-patch:
	${RM} ${WRKSRC}/doc/libmatheval.info

.include <bsd.port.mk>

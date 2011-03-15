# New ports collection makefile for:	NJS
# Date created:				Fri Jan 11 20:45:26 GMT 2002
# Whom:					Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	njs
PORTVERSION=	0.2.5
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTNAME=	js-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NJS (NGS) is a standalone JavaScript/ECMAScript interpreter

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

CONFLICTS=	js-1.5.*

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-shared

MAN1=		js.1 jsdas.1
INFO=		js

post-extract:
	@${RM} ${WRKSRC}/docs/js.info*
# Fix for GCC 4.2
	@${REINPLACE_CMD} -E \
		's,\((unsigned char) \*\) (ptr \+=),\2 sizeof(\1) *,' \
			${WRKSRC}/src/iostream.c

.include <bsd.port.mk>

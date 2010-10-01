# New ports collection makefile for:	cego
# Date created:				Jun 12, 2010
# Whom:					Kurt Jaeger <fbsd-ports@opsec.eu>
#
# $FreeBSD$

PORTNAME=	cego
PORTVERSION=	2.6.14
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	A relational and transactional database system

LIB_DEPENDS=	lfc.1:${PORTSDIR}/devel/lfc \
		lfcxml.1:${PORTSDIR}/devel/lfcxml

LICENSE=	GPLv2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:267:env

.include <bsd.port.mk>

# New ports collection makefile for:	makeplus
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	makeplus
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/_file/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Advanced build system for GNU Make

BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
MAKEPLUS_HOME=	${WRKSRC}
CONFIGURE_ENV=	PATH=${MAKEPLUS_HOME}:${PATH} MAKEPLUS_HOME=${MAKEPLUS_HOME}
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	MAKEPLUS_HOME=${MAKEPLUS_HOME}

MAN1=		make+.1

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./make+

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./make+ install

.include <bsd.port.mk>

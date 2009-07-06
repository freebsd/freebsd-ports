# New ports collection makefile for:	mono-basic
# Date created:		2008-12-20
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	mono-basic
PORTVERSION=	2.4.2
CATEGORIES=	lang
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	VisualBasic.NET support for Mono

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

MAN1=		vbnc.1

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes

tests: build
	@${ECHO_MSG} "===> Running ${PORTNAME} regression tests"
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} test)

.include <bsd.port.mk>

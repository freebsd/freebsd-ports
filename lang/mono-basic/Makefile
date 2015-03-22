# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	mono-basic
PORTVERSION=	3.8
CATEGORIES=	lang
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/ \
		http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	VisualBasic.NET support for Mono

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USES=		gmake mono tar:bzip2

tests: build
	@${ECHO_MSG} "===> Running ${PORTNAME} regression tests"
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} test)

.include <bsd.port.mk>

# New ports collection makefile for:	rebar
# Date created:		2012-06-09
# Whom:			koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rebar
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://github.com/basho/${PORTNAME}/tarball/${GITVERSION}/
DISTNAME=	basho-${PORTNAME}-${GITVERSION}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	A build-tool for Erlang that follows OTP principles

LICENSE=	AL2

BUILD_DEPENDS=	${LOCALBASE}/bin/escript:${PORTSDIR}/lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	bin/${PORTNAME}

GITVERSION=	1c98f6c
FETCH_ARGS=	-Fpr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>

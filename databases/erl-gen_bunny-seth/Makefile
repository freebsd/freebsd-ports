# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	gen_bunny
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	GH
PKGNAMEPREFIX=	erl-
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	RabbitMQ client library for erlang

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	meck>=0:${PORTSDIR}/devel/meck \
	erl-amqp_client-seth>=0:${PORTSDIR}/databases/erl-amqp_client-seth \
	erl-rabbit_common-seth>=0:${PORTSDIR}/databases/erl-rabbit_common-seth

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	seth
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9091b77

PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-build:
	rebar compile

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

.include <bsd.port.mk>

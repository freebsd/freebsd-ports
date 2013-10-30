# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	amqp_client
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=
MASTER_SITES=
PKGNAMEPREFIX=	erl-
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Stripped down distribution of the rabbitmq-erlang-client

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-rabbit_common-seth>=0:${PORTSDIR}/databases/erl-rabbit_common-seth
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-rabbit_common-seth>=0:${PORTSDIR}/databases/erl-rabbit_common-seth

USE_GITHUB=	yes
GH_ACCOUNT=	seth
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7622ad8

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

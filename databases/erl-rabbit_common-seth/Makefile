# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	rabbit_common
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	GH
PKGNAMEPREFIX=	erl-
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Stripped down distribution of the rabbitmq-server code

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-gen_server2-mdaguete>=0:${PORTSDIR}/devel/erl-gen_server2-mdaguete
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-gen_server2-mdaguete>=0:${PORTSDIR}/devel/erl-gen_server2-mdaguete

USE_GITHUB=	yes
GH_ACCOUNT=	seth
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	4c496b5

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

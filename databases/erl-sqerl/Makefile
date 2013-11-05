# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	sqerl
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	erl-

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Database layer originally written for chef

BUILD_DEPENDS=	epgsql>=0:${PORTSDIR}/databases/epgsql \
	erl-pooler>=0:${PORTSDIR}/devel/erl-pooler \
	rebar>=0:${PORTSDIR}/devel/rebar
RUN_DEPENDS=	epgsql>=0:${PORTSDIR}/databases/epgsql \
	erl-pooler>=0:${PORTSDIR}/devel/erl-pooler

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	c371b22
GH_TAGNAME=	${GH_COMMIT}

USE_GMAKE=	yes
ALL_TARGET=	compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/include/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

.include <bsd.port.mk>

# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	couchbeam
PORTVERSION=	0.6.0
PKGNAMEPREFIX=	erl-
#PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	erlang CouchDB framework

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse \
	erl-jiffy>=0:${PORTSDIR}/devel/erl-jiffy \
	erl-erlang-oauth>=0:${PORTSDIR}/net/erl-erlang-oauth \
	mochiweb-basho>=0:${PORTSDIR}/www/mochiweb-basho

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	erl-ibrowse>=0:${PORTSDIR}/net/erl-ibrowse \
	erl-jiffy>=0:${PORTSDIR}/devel/erl-jiffy \
	erl-erlang-oauth>=0:${PORTSDIR}/net/erl-erlang-oauth \
	mochiweb-basho>=0:${PORTSDIR}/www/mochiweb-basho

USE_GITHUB=	yes
GH_ACCOUNT=	opscode
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	old_api
GH_COMMIT=	c7881f6

USE_GMAKE=	yes
ALL_TARGET=		compile
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

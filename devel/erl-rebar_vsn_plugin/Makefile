# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	rebar_vsn_plugin
PORTVERSION=	0.0.4
PKGNAMEPREFIX=	erl-
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	GH
MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	calculate version for an Erlang application

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	rebar>=0:${PORTSDIR}/devel/rebar

USE_GITHUB=	yes
GH_ACCOUNT=	erlware
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	4351400

USE_GMAKE=	yes
ALL_TARGET=		compile
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

do-install:
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL} -d ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/ebin/*.app  ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>

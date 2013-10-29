# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	erlware_commons
PORTVERSION=	0.11.0
PKGNAMEPREFIX=	erl-
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Extension to the Erlang stdlib

BUILD_DEPENDS=	rebar>=0:${PORTSDIR}/devel/rebar \
	erl-rebar_vsn_plugin>=0:${PORTSDIR}/devel/erl-rebar_vsn_plugin

RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
	rebar>=0:${PORTSDIR}/devel/rebar

USE_GITHUB=	yes
GH_ACCOUNT=	erlware
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	0fbd457

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

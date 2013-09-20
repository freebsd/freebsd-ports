# Created by: Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
# $FreeBSD$

PORTNAME=	sqerl
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Database layer originally written for chef

BUILD_DEPENDS=	epgsql>=0:${PORTSDIR}/databases/epgsql \
	pooler>=0:${PORTSDIR}/devel/pooler \
	rebar>=0:${PORTSDIR}/devel/rebar \
	git>=0:${PORTSDIR}/devel/git
RUN_DEPENDS=	epgsql>=0:${PORTSDIR}/databases/epgsql \
	pooler>=0:${PORTSDIR}/devel/pooler

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
#	${INSTALL_DATA} ${WRKSRC}/src/*.hrl   ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

.include <bsd.port.mk>

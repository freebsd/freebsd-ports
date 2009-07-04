# New ports collection makefile for:	thrift
# Date created:	   5 July 2009
# Whom:		   Bruce Simpson
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	20090622
CATEGORIES=	devel
PKGNAMEPREFIX=	erlang-
DISTFILES=

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Erlang interface to Thrift

RUN_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract \
		erlc:${PORTSDIR}/lang/erlang

USE_GMAKE=	yes

ERLC?=		erlc
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

MAKE_ARGS+=	ERLC=${ERLC}

PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		ERLANGDIR=${ERLANGDIR:S/^${PREFIX}\///}

.include <bsd.port.pre.mk>

post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/erl ${WRKSRC}

do-patch:
	${REINPLACE_CMD} '/^ERLC = / s/erlc/${ERLC}/' \
	    ${WRKSRC}/build/buildtargets.mk
	${REINPLACE_CMD} "/^THRIFT_VSN=/s/0\.1/${PORTVERSION}/" \
	     ${WRKSRC}/vsn.mk

# Gnarly and ripped off from erlang-mysql; no bsd.erlang.mk yet.
do-install:
	@${MKDIR} ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	@${MKDIR} ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include
	@(cd ${WRKSRC} && \
	    ${INSTALL_DATA} src/*.erl \
	        ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src && \
	    ${INSTALL_DATA} src/*.src \
	        ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src && \
	    ${INSTALL_DATA} ebin/*.app \
	        ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin && \
	    ${INSTALL_DATA} ebin/*.beam \
	        ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin && \
	    ${INSTALL_DATA} include/*.hrl \
	        ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include)

.include <bsd.port.post.mk>

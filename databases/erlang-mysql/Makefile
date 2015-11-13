# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	mysql
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	databases
MASTER_SITES=	https://support.process-one.net/doc/download/attachments/415/ \
		http://mirror.inerd.com/FreeBSD/distfiles/erlang-mysql/
PKGNAMEPREFIX=	erlang-
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Native MySQL driver for Erlang

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

ERLC?=		erlc
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		ERLANGDIR=${ERLANGDIR:S/^${PREFIX}\///}

do-build:
	cd ${WRKSRC} && ${ERLC} *.erl

do-install:
	@${MKDIR} ${STAGEDIR}${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	@${MKDIR} ${STAGEDIR}${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

	cd ${WRKSRC}									\
	  && ${INSTALL_DATA} *.erl ${STAGEDIR}${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src		\
	  && ${INSTALL_DATA} *.beam ${STAGEDIR}${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin	\
	  && ${INSTALL_DATA} *.hrl ${STAGEDIR}${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

.include <bsd.port.mk>

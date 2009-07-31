# New ports collection makefile for:	erlang-mysql
# Date Created:				2006-05-04
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	https://support.process-one.net/doc/download/attachments/415/ \
		http://mirror.inerd.com/FreeBSD/distfiles/erlang-mysql/
PKGNAMEPREFIX=	erlang-
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Native MySQL driver for Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	${BUILD_DEPENDS}

ERLC?=		erlc
ERLANGDIR?=	${PREFIX}/lib/erlang/lib

PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		ERLANGDIR=${ERLANGDIR:S/^${PREFIX}\///}

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC} && ${ERLC} *.erl

do-install:
	@${MKDIR} ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src
	@${MKDIR} ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

	cd ${WRKSRC}									\
	  && ${INSTALL_DATA} *.erl ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/src		\
	  && ${INSTALL_DATA} *.beam ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/ebin	\
	  && ${INSTALL_DATA} *.hrl ${ERLANGDIR}/${PORTNAME}-${PORTVERSION}/include

.include <bsd.port.post.mk>

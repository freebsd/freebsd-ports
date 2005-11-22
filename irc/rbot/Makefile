# New ports collection makefile for:	rbot
# Date created:		14 Apr 2002
# Whom:			David Bushong <david+ports@bushong.net>
#
# $FreeBSD$
#

PORTNAME=	rbot
PORTVERSION=	0.9.9
PORTREVISION=	0
CATEGORIES=	irc ruby
MASTER_SITES=	http://linuxbrit.co.uk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	david+ports@bushong.net
COMMENT=	Ruby IRC bot similar to infobot

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

USE_RUBY=	yes
USE_RUBY_FEATURES=	rexml
USE_RUBY_SETUP=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --datadir=${PREFIX}/share/doc/${RUBY_NAME}

.include <bsd.port.mk>

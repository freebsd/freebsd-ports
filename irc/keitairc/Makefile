# New ports collection makefile for:	keitairc
# Date created:		11 Nov 2005
# Whom:			Makoto Matsushita <matusita@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	keitairc
PORTVERSION=	1.29
CATEGORIES=	irc
MASTER_SITES=	http://keitairc.sourceforge.jp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	#empty

MAINTAINER=	matusita@FreeBSD.org
COMMENT=IRC proxy for mobilephone that have a web interface

RUN_DEPENDS=	${SITE_PERL}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig

PLIST_FILES=	bin/keitairc

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
USE_REINPLACE=	YES
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}

do-patch:
	${REINPLACE_CMD} -e "s,^#!/usr/bin/perl$$,#!${PERL}," ${WRKSRC}/keitairc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keitairc ${PREFIX}/bin

.include <bsd.port.mk>

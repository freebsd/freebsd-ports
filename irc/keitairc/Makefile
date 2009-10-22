# New ports collection makefile for:	keitairc
# Date created:		11 Nov 2005
# Whom:			Makoto Matsushita <matusita@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	keitairc
PORTVERSION=	1.33
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR= ${PORTNAME}/27571
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	#empty

MAINTAINER=	matusita@FreeBSD.org
COMMENT=IRC proxy for mobilephone that have a web interface

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unicode/Japanese.pm:${PORTSDIR}/japanese/p5-Unicode-Japanese \
		${SITE_PERL}/POE/Component/IRC.pm:${PORTSDIR}/irc/p5-POE-Component-IRC \
		${SITE_PERL}/POE/Component/Pluggable.pm:${PORTSDIR}/devel/p5-POE-Component-Pluggable \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Proc/Daemon.pm:${PORTSDIR}/devel/p5-Proc-Daemon \
		${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig

PLIST_FILES=	bin/keitairc

CONFLICTS=	keitairc-2.*
NO_BUILD=	YES
NO_LATEST_LINK=	YES
NO_WRKSUBDIR=	YES
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	-p
EXTRACT_AFTER_ARGS=	${WRKDIR}

USE_PERL5=	yes

post-patch:
	${REINPLACE_CMD} -e "s,^#!/usr/bin/perl$$,#!${PERL}," ${WRKSRC}/keitairc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keitairc ${PREFIX}/bin

.include <bsd.port.mk>

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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC proxy for mobilephone that have a web interface

RUN_DEPENDS=	ja-p5-Unicode-Japanese>=0:${PORTSDIR}/japanese/p5-Unicode-Japanese \
		p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-POE-Component-Pluggable>=0:${PORTSDIR}/devel/p5-POE-Component-Pluggable \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
		p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig

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

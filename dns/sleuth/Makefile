# New ports collection makefile for:	sleuth
# Date created:			Jun 15, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	sleuth
PORTVERSION=	1.4
CATEGORIES=	dns
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/mj/net/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A tool for checking DNS zones

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5=	yes

post-patch:
	${PERL} -pi -e "s|/etc/sleuth.conf|${PREFIX}/etc/sleuth.conf|g; \
		s|#!/usr/bin/perl|#!${PERL}|g;" ${WRKSRC}/sleuth

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sleuth ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sleuth.conf ${PREFIX}/etc/sleuth.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

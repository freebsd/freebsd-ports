# New ports collection makefile for:	dailystrips
# Date created:				13 July 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	dailystrips
PORTVERSION=	1.0.28
PORTREVISION=	1
CATEGORIES=	deskutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Utility to download or view your favorite online comic strips daily

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} 's|^#!/usr/bin/perl|#!${PERL}|; \
		s!/usr/share/dailystrips/strips.def!${DATADIR}/strips.def!' \
		${WRKSRC}/dailystrips ${WRKSRC}/dailystrips-clean \
		${WRKSRC}/dailystrips-update

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips-clean ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips-update ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/strips.def ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README README.DEFS README.LOCAL README.dailystrips-clean \
    README.dailystrips-update
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

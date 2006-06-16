# New ports collection makefile for:	PFProAPI
# Date created:				13 June 2006
# Whom:					Alexandr Kovalenko <never@nevermind.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	PFProAPI
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	#https://manager.verisign.com/
PKGNAMEPREFIX=	p5-
DISTNAME=	pfpro_freebsd

MAINTAINER=	never@nevermind.kiev.ua
COMMENT=	PFProAPI - Perl support for Payflow Pro calls

BUILD_DEPENDS=	pfpro:${PORTSDIR}/finance/pfpro
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/verisign/payflowpro/freebsd/perl
PERL_CONFIGURE=	yes

MAN3=		PFProAPI.3

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/PFProAPI.pm

.include <bsd.port.mk>

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
COMMENT=	Perl bindings for VeriSign's PayFlow Pro SDK

BUILD_DEPENDS=	pfpro:${PORTSDIR}/finance/pfpro
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/verisign/payflowpro/freebsd/perl
PERL_CONFIGURE=	yes

MAN3=		PFProAPI.3

.include <bsd.port.pre.mk>

RESTRICTED=	Only for VeriSign PayFlow Pro customers
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		${RESTRICTED}. See ${PORTSDIR}/finance/pfpro for instructions
.endif

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${LOCALBASE}|" ${WRKSRC}/PFProAPI.pm

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	1.10
CATEGORIES=	converters perl5
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	p5-
DISTNAME=	buganini-bsdconv-23ad46a91dded05668823e067e3dff69b4c49585

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LIB_DEPENDS=	bsdconv.1:${PORTSDIR}/converters/bsdconv

PERL_CONFIGURE=	yes

MAN3=	bsdconv.3

WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/perl

.include <bsd.port.mk>

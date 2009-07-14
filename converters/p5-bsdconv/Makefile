# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	2.1
CATEGORIES=	converters perl5
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	p5-
DISTNAME=	buganini-bsdconv-36bc34d41e81babc57f55d490c962c6452f14ccd

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LIB_DEPENDS=	bsdconv.2:${PORTSDIR}/converters/bsdconv

PERL_CONFIGURE=	yes

MAN3=		bsdconv.3

WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/perl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

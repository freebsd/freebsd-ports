# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	3.6.2
CATEGORIES=	converters perl5
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	p5-
DISTNAME=	buganini-bsdconv-3.6.2-0-g66aab4b

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LIB_DEPENDS=	bsdconv.3:${PORTSDIR}/converters/bsdconv

PERL_CONFIGURE=	yes

MAN3=		bsdconv.3

WRKSRC=		${WRKDIR}/buganini-bsdconv-66aab4b/wrapper/perl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	3.3
CATEGORIES=	converters perl5
MASTER_SITES=	http://security-hole.info/distfile/
PKGNAMEPREFIX=	p5-
DISTNAME=	buganini-bsdconv-a500cb452f12d583fd545dc901dfca89c84b987e

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LIB_DEPENDS=	bsdconv.3:${PORTSDIR}/converters/bsdconv

PERL_CONFIGURE=	yes

MAN3=		bsdconv.3

WRKSRC=		${WRKDIR}/${DISTNAME}/wrapper/perl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

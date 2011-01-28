# New ports collection makefile for:	p5-bsdconv
# Date created:				29 May 2009
# Whom:	      				buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	bsdconv
PORTVERSION=	4.3
CATEGORIES=	converters perl5
MASTER_SITES=	http://cloud.github.com/downloads/buganini/bsdconv/
PKGNAMEPREFIX=	p5-

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LIB_DEPENDS=	bsdconv.4:${PORTSDIR}/converters/bsdconv

PERL_CONFIGURE=	yes

MAN3=		bsdconv.3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/wrapper/perl

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

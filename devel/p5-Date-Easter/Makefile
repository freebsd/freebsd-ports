# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Date-Easter
PORTVERSION=	1.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Calculates Easter for any given year

LICENSE=	ART20

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/EXE_FILES/d' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

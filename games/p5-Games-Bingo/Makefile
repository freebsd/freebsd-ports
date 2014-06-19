# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Games-Bingo
PORTVERSION=	0.15
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Bingo game Perl implementation

USES=		perl5
USE_PERL5=	modbuild

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::/d' ${WRKSRC}/Build.PL

.include <bsd.port.mk>

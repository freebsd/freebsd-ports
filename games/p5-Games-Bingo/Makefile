# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Games-Bingo
PORTVERSION=	0.15
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A bingo game Perl implementation

USES=		perl5
USE_PERL5=	modbuild

MAN1=		bingo.pl.1
MAN3=		Games::Bingo.3 \
		Games::Bingo::Card.3 \
		Games::Bingo::Column.3 \
		Games::Bingo::ColumnCollection.3 \
		Games::Bingo::Constants.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::/d' ${WRKSRC}/Build.PL

.include <bsd.port.post.mk>

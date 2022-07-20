PORTNAME=	Games-Bingo
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	games perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Bingo game Perl implementation

USES=		perl5
USE_PERL5=	modbuild

post-patch:
	@${REINPLACE_CMD} -i '' '/Test::/d' ${WRKSRC}/Build.PL
	@${REINPLACE_CMD} -i '' '/Pod::/d' ${WRKSRC}/Build.PL

.include <bsd.port.mk>

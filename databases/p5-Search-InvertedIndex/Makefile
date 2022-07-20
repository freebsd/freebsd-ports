PORTNAME=	Search-InvertedIndex
PORTVERSION=	1.17
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manager for inverted index maps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-NamedParms>=1.04:devel/p5-Class-NamedParms \
		p5-Class-ParmList>=1.03:devel/p5-Class-ParmList \
		p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Tie-DB_File-SplitHash>=1.01:devel/p5-Tie-DB_File-SplitHash \
		p5-Tie-FileLRUCache>=1.01:devel/p5-Tie-FileLRUCache

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

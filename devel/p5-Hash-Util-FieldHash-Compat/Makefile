PORTNAME=	Hash-Util-FieldHash-Compat
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use Hash::Util::FieldHash or ties, depending on availability

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Tie-RefHash-Weak>=0.08:devel/p5-Tie-RefHash-Weak

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

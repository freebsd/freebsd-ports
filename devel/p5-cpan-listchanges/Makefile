PORTNAME=	cpan-listchanges
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to list changes for CPAN modules

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-CPAN-DistnameInfo>=0:devel/p5-CPAN-DistnameInfo \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-YAML>=0:textproc/p5-YAML \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>

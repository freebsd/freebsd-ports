PORTNAME=	Test2-Harness
PORTVERSION=	1.000161
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test2 Harness designed for the Test2 event system
WWW=		https://metacpan.org/release/Test2-Harness

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-UUID>=0:devel/p5-Data-UUID \
		p5-Importer>=0.025:devel/p5-Importer \
		p5-Long-Jump>=0.000001:devel/p5-Long-Jump \
		p5-Scope-Guard>=0:devel/p5-Scope-Guard \
		p5-Term-Table>=0.015:devel/p5-Term-Table \
		p5-Test2-Plugin-MemUsage>=0.002002:devel/p5-Test2-Plugin-MemUsage \
		p5-Test2-Plugin-UUID>=0.002001:devel/p5-Test2-Plugin-UUID \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		p5-goto-file>=0.005:devel/p5-goto-file

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	skipv:2.000005

OPTIONS_DEFINE=	RECOMMENDED
OPTIONS_DEFAULT=RECOMMENDED
RECOMMENDED_DESC=	Recommended dependencies by upstream

RECOMMENDED_BUILD_DEPENDS=	p5-Cpanel-JSON-XS>=0:converters/p5-Cpanel-JSON-XS \
			p5-Email-Stuffer>=0.016:mail/p5-Email-Stuffer \
			p5-HTTP-Tiny-Multipart>=0.08:www/p5-HTTP-Tiny-Multipart \
			p5-IO-Pager>=1.00:devel/p5-IO-Pager \
			p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
			p5-Test2-Plugin-Cover>=0.000025:devel/p5-Test2-Plugin-Cover \
			p5-Test2-Plugin-DBIProfile>=0.002002:devel/p5-Test2-Plugin-DBIProfile \
			p5-Test2-Plugin-IOEvents>=0.001001:devel/p5-Test2-Plugin-IOEvents
RECOMMENDED_RUN_DEPENDS=p5-Cpanel-JSON-XS>=0:converters/p5-Cpanel-JSON-XS \
			p5-Email-Stuffer>=0.016:mail/p5-Email-Stuffer \
			p5-HTTP-Tiny-Multipart>=0.08:www/p5-HTTP-Tiny-Multipart \
			p5-IO-Pager>=1.00:devel/p5-IO-Pager \
			p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
			p5-Test2-Plugin-Cover>=0.000025:devel/p5-Test2-Plugin-Cover \
			p5-Test2-Plugin-DBIProfile>=0.002002:devel/p5-Test2-Plugin-DBIProfile \
			p5-Test2-Plugin-IOEvents>=0.001001:devel/p5-Test2-Plugin-IOEvents

.include <bsd.port.mk>

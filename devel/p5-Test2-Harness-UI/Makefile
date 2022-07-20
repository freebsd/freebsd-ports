PORTNAME=	Test2-Harness-UI
PORTVERSION=	0.000119
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:EXODIST
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web interface for viewing and inspecting yath test logs

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-Crypt-Eksblowfish>=0:security/p5-Crypt-Eksblowfish \
		p5-DBI>=0:databases/p5-DBI \
		p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-DBIx-Class-Helpers>=0:databases/p5-DBIx-Class-Helpers \
		p5-DBIx-Class-InflateColumn-Serializer>=0:databases/p5-DBIx-Class-InflateColumn-Serializer \
		p5-DBIx-Class-Schema-Loader>=0:databases/p5-DBIx-Class-Schema-Loader \
		p5-DBIx-Class-Tree>=0:databases/p5-DBIx-Class-Tree \
		p5-DBIx-Class-UUIDColumns>=0:databases/p5-DBIx-Class-UUIDColumns \
		p5-DBIx-QuickDB>=0.000020:databases/p5-DBIx-QuickDB \
		p5-Data-GUID>=0:devel/p5-Data-GUID \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-MySQL>=0:devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-Pg>=0:devel/p5-DateTime-Format-Pg \
		p5-Email-Sender>=0:mail/p5-Email-Sender \
		p5-Email-Simple>=0:mail/p5-Email-Simple \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-Importer>=0.025:devel/p5-Importer \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Plack-Middleware-DBIx-DisconnectAll>=0:www/p5-Plack-Middleware-DBIx-DisconnectAll \
		p5-Plack>=0:www/p5-Plack \
		p5-Router-Simple>=0:www/p5-Router-Simple \
		p5-Starman>=0:www/p5-Starman \
		p5-Statistics-Basic>=0:math/p5-Statistics-Basic \
		p5-Test2-Harness>=1.000112:devel/p5-Test2-Harness \
		p5-Test2-Suite>=0.000126:devel/p5-Test2-Suite \
		p5-Text-Xslate>=0:textproc/p5-Text-Xslate \
		p5-Time-Elapsed>=0.33:devel/p5-Time-Elapsed
TEST_DEPENDS=	p5-HTTP-Tiny-UNIX>=0:www/p5-HTTP-Tiny-UNIX

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	Prophet
PORTVERSION=	0.751
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IOANR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Distributed database system

LICENSE=	MIT

BUILD_DEPENDS=	p5-Any-Moose>=0.04:devel/p5-Any-Moose \
		p5-Config-GitLike>=1.02:devel/p5-Config-GitLike \
		p5-DBD-SQLite>=1:databases/p5-DBD-SQLite \
		p5-DBI>=1:databases/p5-DBI \
		p5-Exporter-Lite>=0:devel/p5-Exporter-Lite \
		p5-File-ShareDir>=1.00:devel/p5-File-ShareDir \
		p5-libwww>=0:www/p5-libwww \
		p5-HTTP-Server-Simple>=0.40:www/p5-HTTP-Server-Simple \
		p5-IPC-Run3>=0:devel/p5-IPC-Run3 \
		p5-JSON>=2.00:converters/p5-JSON \
		p5-JSON-XS>=2.22:converters/p5-JSON-XS \
		p5-MIME-Base64-URLSafe>=0:converters/p5-MIME-Base64-URLSafe \
		p5-Module-Refresh>=0:devel/p5-Module-Refresh \
		p5-Mouse>=0.21:devel/p5-Mouse \
		p5-Net-Bonjour>=0:dns/p5-Net-Bonjour \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Path-Dispatcher>=0.14:devel/p5-Path-Dispatcher \
		p5-Path-Dispatcher-Declarative>=0:devel/p5-Path-Dispatcher-Declarative \
		p5-Proc-InvokeEditor>=0:editors/p5-Proc-InvokeEditor \
		p5-Template-Declare>=0.35:textproc/p5-Template-Declare \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl \
		p5-Time-Progress>=0:devel/p5-Time-Progress \
		p5-URI>=0:net/p5-URI \
		p5-UUID-Tiny>=1.02:devel/p5-UUID-Tiny \
		p5-XML-Atom-SimpleFeed>=0:textproc/p5-XML-Atom-SimpleFeed \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.26:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

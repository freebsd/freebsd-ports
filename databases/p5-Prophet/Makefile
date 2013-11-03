# $FreeBSD$

PORTNAME=	Prophet
PORTVERSION=	0.751
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IOANR
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Prophet is a distributed database system

LICENSE=	MIT

BUILD_DEPENDS=	p5-Any-Moose>=0.04:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Config-GitLike>=1.02:${PORTSDIR}/devel/p5-Config-GitLike \
		p5-DBD-SQLite>=1:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=1:${PORTSDIR}/databases/p5-DBI \
		p5-Exporter-Lite>=0:${PORTSDIR}/devel/p5-Exporter-Lite \
		p5-File-ShareDir>=1.00:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Server-Simple>=0.40:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-JSON>=2.00:${PORTSDIR}/converters/p5-JSON \
		p5-JSON-XS>=2.22:${PORTSDIR}/converters/p5-JSON-XS \
		p5-MIME-Base64-URLSafe>=0:${PORTSDIR}/converters/p5-MIME-Base64-URLSafe \
		p5-Module-Refresh>=0:${PORTSDIR}/devel/p5-Module-Refresh \
		p5-Mouse>=0.21:${PORTSDIR}/devel/p5-Mouse \
		p5-Net-Bonjour>=0:${PORTSDIR}/dns/p5-Net-Bonjour \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Path-Dispatcher>=0.14:${PORTSDIR}/devel/p5-Path-Dispatcher \
		p5-Path-Dispatcher-Declarative>=0:${PORTSDIR}/devel/p5-Path-Dispatcher-Declarative \
		p5-Proc-InvokeEditor>=0:${PORTSDIR}/editors/p5-Proc-InvokeEditor \
		p5-Template-Declare>=0.35:${PORTSDIR}/textproc/p5-Template-Declare \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Perl>=0:${PORTSDIR}/devel/p5-ReadLine-Perl \
		p5-Time-Progress>=0:${PORTSDIR}/devel/p5-Time-Progress \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-UUID-Tiny>=1.02:${PORTSDIR}/devel/p5-UUID-Tiny \
		p5-XML-Atom-SimpleFeed>=0:${PORTSDIR}/textproc/p5-XML-Atom-SimpleFeed \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.26:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

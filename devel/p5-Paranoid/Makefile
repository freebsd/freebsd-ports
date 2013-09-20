# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	Paranoid
PORTVERSION=	0.36
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Paranoia support for safer programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-BerkeleyDB>=0.32:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Unix-Syslog>=1.1:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USES=		perl5
USE_PERL5=	configure

MAN3=		Paranoid::Data.3 \
		Paranoid::Log::File.3 \
		Paranoid::Log::Email.3 \
		Paranoid::Args.3 \
		Paranoid::Lockfile.3 \
		Paranoid.3 \
		Paranoid::Log.3 \
		Paranoid::Glob.3 \
		Paranoid::Input.3 \
		Paranoid::Log::Syslog.3 \
		Paranoid::Filesystem.3 \
		Paranoid::Process.3 \
		Paranoid::BerkeleyDB.3 \
		Paranoid::Module.3 \
		Paranoid::Network.3 \
		Paranoid::Network::IPv4.3 \
		Paranoid::Network::IPv6.3 \
		Paranoid::Network::Socket.3 \
		Paranoid::Log::Buffer.3 \
		Paranoid::Debug.3

NO_STAGE=	yes
.include <bsd.port.mk>

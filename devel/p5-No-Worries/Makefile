# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	No-Worries
PORTVERSION=	0.8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	No::Worries - coding without worries

BUILD_DEPENDS=	p5-HTTP-Date>=0:${PORTSDIR}/www/p5-HTTP-Date \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	No::Worries.3 \
	No::Worries::DN.3 \
	No::Worries::Date.3 \
	No::Worries::Die.3 \
	No::Worries::Dir.3 \
	No::Worries::Export.3 \
	No::Worries::File.3 \
	No::Worries::Log.3 \
	No::Worries::PidFile.3 \
	No::Worries::Proc.3 \
	No::Worries::Stat.3 \
	No::Worries::String.3 \
	No::Worries::Syslog.3 \
	No::Worries::Warn.3

.include <bsd.port.mk>

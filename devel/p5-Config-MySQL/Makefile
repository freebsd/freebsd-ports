# $FreeBSD$

PORTNAME=	Config-MySQL
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to read/write MySQL-style configuration files

RUN_DEPENDS=	\
	p5-Config-INI>0:${PORTSDIR}/devel/p5-Config-INI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Config::MySQL.3 \
	Config::MySQL::Reader.3 \
	Config::MySQL::Writer.3

NO_STAGE=	yes
.include <bsd.port.mk>

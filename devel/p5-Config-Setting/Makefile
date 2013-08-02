# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	Config-Setting
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class that provides an easy interface to use config files

RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Config::Setting.3 \
	Config::Setting::Chunk.3 \
	Config::Setting::FileProvider.3 \
	Config::Setting::IniParser.3 \
	Config::Setting::XMLParser.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Config-Setting
# Date created:				1 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Config-Setting
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.happygiraffe.net/dist/
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A class that provides an easy interface to use config files

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	yes

MAN3=	Config::Setting.3 \
	Config::Setting::Fileprovider.3 \
	Config::Setting::IniParser.3 \
	Config::Setting::XMLParser.3

.include <bsd.port.mk>

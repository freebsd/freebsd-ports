# New ports collection makefile for:	p5-Config-Setting
# Date created:				1 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Config-Setting
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.myrddin.demon.co.uk/dist/
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Config::Setting.3 \
	Config::Setting::Fileprovider.3 \
	Config::Setting::IniParser.3 \
	Config::Setting::XMLParser.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Config-IniFiles
# Date created:				October 21st 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Config-IniFiles
PORTVERSION=	2.71
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Perl5 module for reading .ini-style configuration files

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=		Config::IniFiles.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>

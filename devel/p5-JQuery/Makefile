# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	JQuery
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PETERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Interface to Jquery, a language based on JavaScript

RUN_DEPENDS=	p5-CGI-Application>=0:${PORTSDIR}/www/p5-CGI-Application \
		p5-CSS>=0:${PORTSDIR}/textproc/p5-CSS \
		p5-HTML-Table>=0:${PORTSDIR}/www/p5-HTML-Table \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	modbuild

SHEBANG_FILES=	lib/JQuery/cgi-bin/*.pl

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Lexical-Var
# Date created:		2012-02-24
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lexical-Var
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
#MASTER_SITE_SUBDIR=	CPAN:ZEFRAM

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for static variables without namespace pollution

BUILD_DEPENDS=	p5-Lexical-SealRequireHints>=0:${PORTSDIR}/devel/p5-Lexical-SealRequireHints
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Lexical::Sub.3 Lexical::Var.3

.include <bsd.port.mk>

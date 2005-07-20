# New ports collection makefile for:    Config-Objective
# Date created:                         Mon Feb 16 15:50:34 CST 2004
# Whom:                                 Jim Pirzyk <pirzyk@uiuc.edu>
#
# $FreeBSD$
#

PORTNAME=	Config-Objective
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	pirzyk@uiuc.edu
COMMENT=	Configuration data as perl objects

BUILD_DEPENDS=	${SITE_PERL}/Parse/Yapp.pm:${PORTSDIR}/devel/p5-Parse-Yapp \
		${SITE_PERL}/Parse/Lex.pm:${PORTSDIR}/devel/p5-ParseLex
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Config::Objective::List.3 Config::Objective::Boolean.3 \
		Config::Objective::Table.3 Config::Objective.3 \
		Config::Objective::Hash.3 Config::Objective::Integer.3 \
		Config::Objective::String.3 Config::Objective::DataType.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6 or newer
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-DateTime-Format-Builder
# Date created:	   2 july 2003
# Whom:		   Mathieu Arnold <m@absolight.net>
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-Builder
PORTVERSION=	0.78.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DateTime
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Create DateTime parser classes and objects

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime

PERL_MODBUILD=	yes

MAN3=		DateTime::Format::Builder.3 DateTime::Format::Builder::Parser.3 \
		DateTime::Format::Builder::Parser::Dispatch.3 \
		DateTime::Format::Builder::Parser::Regex.3 \
		DateTime::Format::Builder::Parser::Quick.3 \
		DateTime::Format::Builder::Parser::Strptime.3 \
		DateTime::Format::Builder::Parser::generic.3 \
		DateTime::Format::Builder::Tutorial.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500600
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	p5-Class-Accessor-Named
# Date created:		2006-07-21
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Class-Accessor-Named
PORTVERSION=	0.003
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Better profiling output for Class::Accessor

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sub/Name.pm:${PORTSDIR}/devel/p5-Sub-Name \
		${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS} \
		${SITE_PERL}/Test/Dependencies.pm:${PORTSDIR}/devel/p5-Test-Dependencies

PERL_CONFIGURE=	yes

MAN3=		Class::Accessor::Named.3

.include <bsd.port.mk>

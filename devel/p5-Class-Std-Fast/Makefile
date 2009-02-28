# New ports collection makefile for:	p5-Class-Std-Fast
# Date created:		28 Feb, 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Class-Std-Fast
DISTVERSION=	v0.0.8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Faster but less secure than Class::Std

BUILD_DEPENDS=	p5-Test-Simple>=0.86:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
		p5-Class-Std>=0.0.9:${PORTSDIR}/devel/p5-Class-Std \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Data-Dumper>=2.121:${PORTSDIR}/devel/p5-Data-Dumper

PERL_CONFIGURE=	YES

MAN3=		Class::Std::Fast.3 Class::Std::Fast::Storable.3

.include <bsd.port.mk>

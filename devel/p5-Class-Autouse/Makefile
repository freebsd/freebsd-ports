# New ports collection makefile for:	Class-Autouse
# Date created:	   10 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Class-Autouse
PORTVERSION=	1.17
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Defer loading of one or more classes

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/List/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/prefork.pm:${PORTSDIR}/devel/p5-prefork
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::Autouse.3

post-patch:
	@${PERL} -pi -e 's/^auto_install.*$$//' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

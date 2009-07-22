# New ports collection makefile for:	File-Flat
# Date created:	   11 December 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	File-Flat
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Implements a flat filesystem

RUN_DEPENDS=	${SITE_PERL}/Test/ClassAPI.pm:${PORTSDIR}/devel/p5-Test-ClassAPI \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/File/NCopy.pm:${PORTSDIR}/devel/p5-File-NCopy \
		${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		${SITE_PERL}/File/Remove.pm:${PORTSDIR}/devel/p5-File-Remove \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/${PERL_ARCH}/IO/File.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/Class/Autouse.pm:${PORTSDIR}/devel/p5-Class-Autouse \
		${SITE_PERL}/prefork.pm:${PORTSDIR}/devel/p5-prefork
BUILD_DEPENDS=	${SITE_PERL}/Test/ClassAPI.pm:${PORTSDIR}/devel/p5-Test-ClassAPI \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/File/NCopy.pm:${PORTSDIR}/devel/p5-File-NCopy \
		${SITE_PERL}/File/Copy/Recursive.pm:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		${SITE_PERL}/File/Remove.pm:${PORTSDIR}/devel/p5-File-Remove \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/${PERL_ARCH}/IO/File.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/Class/Autouse.pm:${PORTSDIR}/devel/p5-Class-Autouse \
		${SITE_PERL}/prefork.pm:${PORTSDIR}/devel/p5-prefork \
		${SITE_PERL}/Test/ClassAPI.pm:${PORTSDIR}/devel/p5-Test-ClassAPI

PERL_CONFIGURE=	yes

MAN3=		File::Flat.3

post-patch:
	@${PERL} -pi -e 's/^auto_install.*$$//' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

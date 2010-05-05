# New ports collection makefile for:	devel/p5-SVN-Mirror
# Date created:				Mar 15 2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Mirror
PORTVERSION=	0.75
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Mirror remote subversion repository to local

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Data/UUID.pm:${PORTSDIR}/devel/p5-Data-UUID \
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/File/chdir.pm:${PORTSDIR}/devel/p5-File-chdir \
		${SITE_PERL}/SVN/Simple/Edit.pm:${PORTSDIR}/devel/p5-SVN-Simple \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/VCP.pm:${PORTSDIR}/devel/p5-VCP-autrijus
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		svm.1
MAN3=		SVN::Mirror.3

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

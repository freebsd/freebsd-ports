# New ports collection makefile for:	devel/p5-SVN-Simple
# Date created:				Mar  2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Simple
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Simple interface to SVN::Delta::Editor

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::Simple::Edit.3 SVN::Simple::Editor.3

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

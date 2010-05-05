# New ports collection makefile for:	devel/p5-SVN-ACL
# Date created:				Jan  2006
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	SVN-ACL
PORTVERSION=	0.02
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A simple ACL frontend for subversion

BUILD_DEPENDS=	\
		${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::ACL.3

.include <bsd.port.mk>

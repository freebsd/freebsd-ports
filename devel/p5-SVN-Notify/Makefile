# Ports collection Makefile for:		SVN::Notify
# Date created:					22 Feb 2005
# Whom:						dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify
PORTVERSION=	2.43
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/D/DW/DWHEELER/
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Subversion activity notification

BUILD_DEPENDS=	${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		svnnotify.1
MAN3=		SVN::Notify.3 SVN::Notify::HTML.3 SVN::Notify::HTML::ColorDiff.3

.include <bsd.port.mk>

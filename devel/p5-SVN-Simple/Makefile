# New ports collection makefile for:	devel/p5-SVN-Simple
# Date created:				Mar  2004
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Simple
PORTVERSION=	0.25
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CL/CLKAO
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@infor.org
COMMENT=	Simple interface to SVN::Delta::Editor

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/subversion-perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SVN::Simple::Edit.3 SVN::Simple::Editor.3

.include <bsd.port.mk>

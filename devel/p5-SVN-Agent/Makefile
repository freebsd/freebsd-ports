# New ports collection makefile for:	p5-SVN-Agent
# Date created:		2006-07-12
# Whom:			Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Agent
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Simple svn manipulation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/subversion-perl \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	SVN::Agent.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	currently requires at least Perl 5.8.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>

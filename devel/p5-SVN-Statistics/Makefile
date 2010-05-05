# New ports collection makefile for:	p5-SVN-Statistics
# Date created:		2006-07-12
# Whom:			Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Statistics
PORTVERSION=	0.041
PORTREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	SVN::Statistics - perl module to create subversion statistics

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		p5-RRDTool-OO>=0:${PORTSDIR}/devel/p5-RRDTool-OO \
		p5-Data-Dumper-Simple>=0:${PORTSDIR}/devel/p5-Data-Dumper-Simple \
		p5-IO-Toolkit>=0:${PORTSDIR}/devel/p5-IO-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	SVN::Statistics.3

.include <bsd.port.mk>

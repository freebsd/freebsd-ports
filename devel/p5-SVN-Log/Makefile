# New ports collection makefile for:	p5-SVN-Log
# Date created:		2006-06-26
# Whom:			Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Log
PORTVERSION=	0.03
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	SVN::Log - Extract change logs from a Subversion server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Core.pm:${PORTSDIR}/devel/p5-subversion \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=	SVN::Log.3

.include <bsd.port.mk>

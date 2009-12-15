# New ports collection makefile for:	devel/p5-App-SVN-Bisect
# Date created:				5 Nov 2009
# Whom:					Rui Paulo <rpaulo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	App-SVN-Bisect
PORTVERSION=	1.0
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Binary search through svn revisions

BUILD_DEPENDS=	p5-IO-All>0:${PORTSDIR}/devel/p5-IO-All \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	svn-bisect.1
MAN3=	App::SVN::Bisect.3

.include <bsd.port.mk>

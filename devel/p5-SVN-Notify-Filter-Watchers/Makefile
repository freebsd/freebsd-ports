# New ports collection makefile for:	SVN-Notify-Filter-Watchers
# Date created:		2008-04-22
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Filter-Watchers
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Subscribe to SVN::Notify commits with a Subversion property

RUN_DEPENDS=	p5-SVN-Notify>=2.72:${PORTSDIR}/devel/p5-SVN-Notify
BUILD_DEPENDS=	p5-SVN-Notify>=2.72:${PORTSDIR}/devel/p5-SVN-Notify

PERL_CONFIGURE=	yes

MAN3=		SVN::Notify::Filter::Watchers.3

.include <bsd.port.mk>

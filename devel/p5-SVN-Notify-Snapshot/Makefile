# New ports collection makefile for:	SVN-Notify-Snapshot
# Date created:		2008-02-14
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Snapshot
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Take snapshots from Subversion activity

BUILD_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify
RUN_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify

OPTIONS=	CONFIG "Enable YAML syntax for post-commit hook" Off

PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_CONFIG)
BUILD_DEPENDS+=	${SITE_PERL}/SVN/Notify/Config.pm:${PORTSDIR}/devel/p5-SVN-Notify-Config
.endif

MAN3=		SVN::Notify::Snapshot.3 SVN::Notify::Snapshot::ConfigData.3

.include <bsd.port.post.mk>

# New ports collection makefile for:	SVN-Notify-Snapshot
# Date created:		2008-02-14
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Snapshot
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Take snapshots from Subversion activity

BUILD_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	CONFIG "Enable YAML syntax for post-commit hook" Off

.include <bsd.port.pre.mk>

.if defined(WITH_CONFIG)
_BUILD_DEPENDS=	${SITE_PERL}/SVN/Notify/Config.pm:${PORTSDIR}/devel/p5-SVN-Notify-Config
BUILD_DEPENDS+=	${_BUILD_DEPENDS}
RUN_DEPENDS+=	${_BUILD_DEPENDS}
.endif

PERL_MODBUILD=	yes

MAN3=		SVN::Notify::Snapshot.3 SVN::Notify::Snapshot::ConfigData.3

.include <bsd.port.post.mk>

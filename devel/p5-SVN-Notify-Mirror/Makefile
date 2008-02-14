# New ports collection makefile for:	SVN-Notify-Mirror
# Date created:		2008-02-13
# Whom:			Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Mirror
PORTVERSION=	0.03603
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	Keep a mirrored working copy of a repository path

RUN_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify

OPTIONS=	CONFIG "Enable YAML syntax for post-commit hook" Off \
		SSH "Enable SSH for remote working copy update" Off \
		RSYNC "Enable rsync for remote working copy update" Off

.include <bsd.port.pre.mk>

.if defined(WITH_CONFIG)
BUILD_DEPENDS+=	${SITE_PERL}/SVN/Notify/Config.pm:${PORTSDIR}/devel/p5-SVN-Notify-Config
.endif

.if defined(WITH_SSH)
BUILD_DEPENDS+=	${SITE_PERL}/Net/SSH.pm:${PORTSDIR}/net/p5-Net-SSH
.endif

.if defined(WITH_RSYNC)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/File/Rsync.pm:${PORTSDIR}/net/p5-File-Rsync
.endif

PERL_MODBUILD=	yes

MAN3=		SVN::Notify::Mirror.3 SVN::Notify::Mirror::ConfigData.3 \
		SVN::Notify::Mirror::Rsync.3 SVN::Notify::Mirror::SSH.3

.include <bsd.port.post.mk>

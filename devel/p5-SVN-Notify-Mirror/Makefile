# New ports collection makefile for:	SVN-Notify-Mirror
# Date created:		2008-02-13
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Mirror
PORTVERSION=	0.038
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Keep a mirrored working copy of a repository path

BUILD_DEPENDS=	p5-SVN-Notify>=2.70:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-YAML>=0.62:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

OPTIONS=	CONFIG "Enable YAML syntax for post-commit hook" Off \
		SSH "Enable SSH for remote working copy update" Off \
		RSYNC "Enable rsync for remote working copy update" Off

.include <bsd.port.pre.mk>

.if defined(WITH_CONFIG)
BUILD_DEPENDS+=	p5-SVN-Notify-Config>=0.0906:${PORTSDIR}/devel/p5-SVN-Notify-Config
.endif

.if defined(WITH_SSH)
BUILD_DEPENDS+=	p5-Net-SSH>=0.08:${PORTSDIR}/net/p5-Net-SSH
.endif

.if defined(WITH_RSYNC)
BUILD_DEPENDS+=	p5-File-Rsync>=0.42:${PORTSDIR}/net/p5-File-Rsync
.endif

MAN3=		SVN::Notify::Mirror.3 SVN::Notify::Mirror::ConfigData.3 \
		SVN::Notify::Mirror::Rsync.3 SVN::Notify::Mirror::SSH.3

.include <bsd.port.post.mk>

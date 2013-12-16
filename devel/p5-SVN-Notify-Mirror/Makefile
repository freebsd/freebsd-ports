# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Mirror
PORTVERSION=	0.040
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keep a mirrored working copy of a repository path

BUILD_DEPENDS=	p5-SVN-Notify>=2.83:${PORTSDIR}/devel/p5-SVN-Notify \
		p5-YAML>=0.81:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		SVN::Notify::Mirror.3 SVN::Notify::Mirror::ConfigData.3 \
		SVN::Notify::Mirror::Rsync.3 SVN::Notify::Mirror::SSH.3

OPTIONS_DEFINE=	CONFIG SSH RSYNC

CONFIG_DESC=	Enable YAML syntax for post-commit hook
SSH_DESC=	Enable SSH for remote working copy update
RSYNC_DESC=	Enable rsync for remote working copy update

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONFIG}
BUILD_DEPENDS+=	p5-SVN-Notify-Config>=0.0906:${PORTSDIR}/devel/p5-SVN-Notify-Config
RUN_DEPENDS+=	p5-SVN-Notify-Config>=0.0906:${PORTSDIR}/devel/p5-SVN-Notify-Config
.endif

.if ${PORT_OPTIONS:MSSH}
BUILD_DEPENDS+=	p5-Net-SSH>=0.08:${PORTSDIR}/net/p5-Net-SSH
RUN_DEPENDS+=	p5-Net-SSH>=0.08:${PORTSDIR}/net/p5-Net-SSH
.endif

.if ${PORT_OPTIONS:MRSYNC}
BUILD_DEPENDS+=	p5-File-Rsync>=0.42:${PORTSDIR}/net/p5-File-Rsync
RUN_DEPENDS+=	p5-File-Rsync>=0.42:${PORTSDIR}/net/p5-File-Rsync
.endif

.include <bsd.port.mk>

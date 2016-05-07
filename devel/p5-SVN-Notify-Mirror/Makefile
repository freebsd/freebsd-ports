# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Mirror
PORTVERSION=	0.040
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Keep a mirrored working copy of a repository path

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-SVN-Notify>=2.83:devel/p5-SVN-Notify \
		p5-YAML>=0.81:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

OPTIONS_DEFINE=	CONFIG SSH RSYNC

CONFIG_DESC=	Enable YAML syntax for post-commit hook
SSH_DESC=	Enable SSH for remote working copy update
RSYNC_DESC=	Enable rsync for remote working copy update

CONFIG_BUILD_DEPENDS=	p5-SVN-Notify-Config>=0.0906:devel/p5-SVN-Notify-Config
CONFIG_RUN_DEPENDS=	p5-SVN-Notify-Config>=0.0906:devel/p5-SVN-Notify-Config
RSYNC_BUILD_DEPENDS=	p5-File-Rsync>=0.42:net/p5-File-Rsync
RSYNC_RUN_DEPENDS=	p5-File-Rsync>=0.42:net/p5-File-Rsync
SSH_BUILD_DEPENDS=	p5-Net-SSH>=0.08:net/p5-Net-SSH
SSH_RUN_DEPENDS=	p5-Net-SSH>=0.08:net/p5-Net-SSH

.include <bsd.port.mk>

# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Snapshot
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Take snapshots from Subversion activity

BUILD_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify
RUN_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify

OPTIONS_DEFINE=	CONFIG
CONFIG_DESC=	Enable YAML syntax for post-commit hook

USES=		perl5
USE_PERL5=	modbuild

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONFIG}
BUILD_DEPENDS+=	p5-SVN-Notify-Config>=0:${PORTSDIR}/devel/p5-SVN-Notify-Config
RUN_DEPENDS+=	p5-SVN-Notify-Config>=0:${PORTSDIR}/devel/p5-SVN-Notify-Config
.endif

MAN3=		SVN::Notify::Snapshot.3 SVN::Notify::Snapshot::ConfigData.3

.include <bsd.port.mk>

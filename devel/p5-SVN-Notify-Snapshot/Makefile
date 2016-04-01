# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Notify-Snapshot
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Take snapshots from Subversion activity

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/bin/svnnotify:devel/p5-SVN-Notify
RUN_DEPENDS=	${LOCALBASE}/bin/svnnotify:devel/p5-SVN-Notify

OPTIONS_DEFINE=	CONFIG
CONFIG_DESC=	Enable YAML syntax for post-commit hook

USES=		perl5
USE_PERL5=	modbuild

CONFIG_BUILD_DEPENDS=	p5-SVN-Notify-Config>=0:devel/p5-SVN-Notify-Config
CONFIG_RUN_DEPENDS=	p5-SVN-Notify-Config>=0:devel/p5-SVN-Notify-Config

.include <bsd.port.mk>

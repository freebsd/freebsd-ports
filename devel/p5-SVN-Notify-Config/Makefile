# New ports collection makefile for:	SVN-Notify-Config
# Date created:		2008-02-12
# Whom:			Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	SVN-Notify-Config
PORTVERSION=	0.0907
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	Perl module for config-driven Subversion notification

RUN_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify \
		${LOCALBASE}/bin/ysh:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${LOCALBASE}/bin/svnnotify:${PORTSDIR}/devel/p5-SVN-Notify \
		${LOCALBASE}/bin/ysh:${PORTSDIR}/textproc/p5-YAML

PERL_MODBUILD=	yes

MAN3=		SVN::Notify::Config.3

.include <bsd.port.mk>

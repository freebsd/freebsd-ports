# New ports collection makefile for:	p5-File-Find-Rule-VCS
# Date created:				March 8th 2009
# Whom:	      				Cezary Morga <cm@therek.net>
#
# $FreeBSD$
#

PORTNAME=	File-Find-Rule-VCS
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cm@therek.net
COMMENT=	Exclude files and directories for Version Control Systems

BUILD_DEPENDS=	p5-File-Find-Rule>=0.20:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Text-Glob>=0.08:${PORTSDIR}/textproc/p5-Text-Glob
RUN_DEPENDS=	p5-File-Find-Rule>=0.20:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Text-Glob>=0.08:${PORTSDIR}/textproc/p5-Text-Glob

PERL_CONFIGURE=	5.5.3+

MAN3=		File::Find::Rule::VCS.3

.include <bsd.port.mk>

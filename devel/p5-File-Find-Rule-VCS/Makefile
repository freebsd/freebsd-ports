# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	File-Find-Rule-VCS
PORTVERSION=	1.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Exclude files and directories for Version Control Systems

BUILD_DEPENDS=	p5-File-Find-Rule>=0.20:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Text-Glob>=0.08:${PORTSDIR}/textproc/p5-Text-Glob
RUN_DEPENDS=	p5-File-Find-Rule>=0.20:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Text-Glob>=0.08:${PORTSDIR}/textproc/p5-Text-Glob

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

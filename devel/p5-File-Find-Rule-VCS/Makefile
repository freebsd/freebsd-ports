# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	File-Find-Rule-VCS
PORTVERSION=	1.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Exclude files and directories for Version Control Systems

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-Find-Rule>=0.20:devel/p5-File-Find-Rule \
		p5-Text-Glob>=0.08:textproc/p5-Text-Glob
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

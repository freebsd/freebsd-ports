# Created by: Christopher Nehren <apeiron@comcast.net>
# $FreeBSD$

PORTNAME=	Shell-Base
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module implementing a simple command shell

BUILD_DEPENDS=	p5-Term-Size>=0:${PORTSDIR}/devel/p5-Term-Size \
		p5-Text-Shellwords>=0:${PORTSDIR}/textproc/p5-Text-Shellwords
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

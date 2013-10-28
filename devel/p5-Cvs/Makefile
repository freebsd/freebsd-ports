# Created by: Philip Drapeau <pdrapeau@advanis.ca>
# $FreeBSD$

PORTNAME=	Cvs
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSOLIV
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cvs - Object oriented interface to the CVS command

RUN_DEPENDS=	p5-IO-Tty>=0:${PORTSDIR}/devel/p5-IO-Tty \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

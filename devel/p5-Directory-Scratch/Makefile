# New ports collection makefile for:	devel/p5-Directory-Scratch
# Date created:				03 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Directory-Scratch
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Easy-to-use self-cleaning scratch space

BUILD_DEPENDS=	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
		p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp \
		p5-String-Random>0:${PORTSDIR}/devel/p5-String-Random
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Directory::Scratch.3

.include <bsd.port.mk>

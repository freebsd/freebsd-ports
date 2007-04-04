# New ports collection makefile for:	devel/p5-File-Attributes-Recursive
# Date created:				04 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Attributes-Recursive
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Inherit file attributes from parent directories

BUILD_DEPENDS=	${SITE_PERL}/Directory/Scratch.pm:${PORTSDIR}/devel/p5-Directory-Scratch \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/File/Attributes.pm:${PORTSDIR}/devel/p5-File-Attributes
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	File::Attributes::Recursive.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		one of the dependencies requires perl5.8
.endif

.include <bsd.port.post.mk>

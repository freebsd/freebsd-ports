# New ports collection makefile for:	devel/p5-File-Attributes
# Date created:				03 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-Attributes
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	File::Attributes - Manipulate file metadata

BUILD_DEPENDS=	${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/Directory/Scratch.pm:${PORTSDIR}/devel/p5-Directory-Scratch \
		${SITE_PERL}/Best.pm:${PORTSDIR}/devel/p5-Best \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	File::Attributes.3 \
	File::Attributes::Base.3 \
	File::Attributes::Simple.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		fails its tests on this version of perl
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	devel/p5-File-ShareDir-PathClass
# Date created:				Aug 10, 2011
# Whom:					Wen Heping <wen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	File-ShareDir-PathClass
PORTVERSION=	1.101620
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	File::ShareDir returning Path::Class objects

BUILD_DEPENDS=	p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		File::ShareDir::PathClass.3

.include <bsd.port.mk>

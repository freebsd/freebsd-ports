# New ports collection makefile for:	p5-Archive-Extract
# Date created:				28 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Archive-Extract
PORTVERSION=	0.26
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A generic archive extracting mechanism

BUILD_DEPENDS=	${SITE_PERL}/IPC/Cmd.pm:${PORTSDIR}/devel/p5-IPC-Cmd
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Archive::Extract.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

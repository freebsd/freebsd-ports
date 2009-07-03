# New ports collection makefile for:	p5-Archive-Extract
# Date created:				28 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Archive-Extract
PORTVERSION=	0.34
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A generic archive extracting mechanism

BUILD_DEPENDS=	p5-IPC-Cmd>=0.42:${PORTSDIR}/devel/p5-IPC-Cmd
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	Archive::Extract.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

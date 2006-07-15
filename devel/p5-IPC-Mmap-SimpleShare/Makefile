# New ports collection makefile for:	p5-IPC-Mmap-SimpleShare
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	IPC-Mmap-SimpleShare
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Safely share structures among processes using anonymous mmap

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IPC/Mmap.pm:${PORTSDIR}/devel/p5-IPC-Mmap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IPC::Mmap::SimpleShare.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800	# Inherited from devel/p5-IPC-Mmap
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>

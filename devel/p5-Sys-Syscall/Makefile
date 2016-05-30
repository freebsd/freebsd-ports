# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Sys-Syscall
PORTVERSION=	0.25
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Access system calls that Perl doesn't provide access to

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/Sys/Syscall.pm.orig

.include <bsd.port.mk>

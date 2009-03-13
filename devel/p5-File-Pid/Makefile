# New ports collection makefile for:	p5-File-Pid
# Date created:		2006-09-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	File-Pid
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Pid File Manipulation

RUN_DEPENDS=	${SITE_PERL}/Class/Accessor/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Pid.3

post-patch:
	${RM} ${WRKSRC}/lib/File/Pid.pm.orig

.include <bsd.port.mk>

# New ports collection makefile for:	Filesys::Notify::KQueue
# Date created:		05 Mar 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Notify-KQueue
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to wrap IO::KQueue for watching file system

RUN_DEPENDS=	\
	p5-IO-KQueue>0:${PORTSDIR}/devel/p5-IO-KQueue
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Filesys::Notify::KQueue.3 \
	Filesys::Notify::README.3

.include <bsd.port.mk>

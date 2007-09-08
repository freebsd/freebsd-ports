# New ports collection makefile for:	devel/p5-Filesys-Virtual-Plain
# Date created:				05 February 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Virtual-Plain
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Plain virtual filesystem

BUILD_DEPENDS=	p5-Filesys-Virtual>=0.05:${PORTSDIR}/devel/p5-Filesys-Virtual
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Filesys::Virtual::Plain.3

.include <bsd.port.mk>

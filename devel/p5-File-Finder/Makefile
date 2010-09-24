# New ports collection makefile for:	devel/p5-File-Finder
# Date created:				Mar 21 2007
# Whom:					lth@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	File-Finder
PORTVERSION=	0.53
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Nice wrapper for File::Find ala find(1)

RUN_DEPENDS=	p5-Text-Glob>0:${PORTSDIR}/textproc/p5-Text-Glob
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		File::Finder.3 \
		File::Finder::Steps.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>

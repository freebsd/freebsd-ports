# ex:ts=8
# Ports collection makefile for:	p5-VCG
# Date created:			Mar 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	VCG
PORTVERSION=	0.5
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/T/TE/TEEJAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interface to the VCG graphing tool

BUILD_DEPENDS=	${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run
RUN_DEPENDS=	${BUILD_DEPENDS} \
		xvcg:${PORTSDIR}/graphics/vcg

PERL_CONFIGURE=	yes

MAN3=	VCG.3

.include <bsd.port.mk>

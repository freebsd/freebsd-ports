# New ports collection makefile for:	GTop
# Date Created:				08 Oct 2003
# Whom:					Trevor Cornpropst <tcornpropst@cox.net>
#
# $FreeBSD$
#

PORTNAME=	GTop
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=GTop
PKGNAMEPREFIX=	p5-

MAINTAINER=	tcornpropst@cox.net
COMMENT=	A Perl interface to libgtop

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop

PERL_CONFIGURE=	YES

MAN3=		GTop.3

.include <bsd.port.mk>

# New ports collection makefile for:	IPC-MM
# Date created:	   09 August 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	IPC-MM
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	IPC
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to Ralf Engelschall's mm library

LIB_DEPENDS=	mm.13:${PORTSDIR}/devel/mm

PERL_CONFIGURE=	yes

MAN3=		IPC::MM.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-Locale-PO
# Date created:		2008-12-22
# Whom:			Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Locale-PO
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Perl module for manipulating .po entries from GNU gettext

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}

BUILD_DEPENDS=	${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Locale::PO.3

.include <bsd.port.mk>

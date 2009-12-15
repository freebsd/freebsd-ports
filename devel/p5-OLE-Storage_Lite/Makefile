# New ports collection makefile for:		p5-OLE-Storage_Lite
# Date created:					April 2, 2001
# Whom:						Jason Portwood <jason@iac.net>
#
# $FreeBSD$
#

PORTNAME=	OLE-Storage_Lite
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for OLE document interface

BUILD_DEPENDS=	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		OLE::Storage_Lite.3

.include <bsd.port.mk>

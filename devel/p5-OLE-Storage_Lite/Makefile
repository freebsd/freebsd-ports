# New ports collection makefile for:		p5-OLE-Storage_Lite
# Date created:					April 2, 2001
# Whom:						Jason Portwood <jason@iac.net>
#
# $FreeBSD$
#

PORTNAME=	OLE-Storage_Lite
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	OLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		OLE::Storage_Lite.3

.include <bsd.port.mk>

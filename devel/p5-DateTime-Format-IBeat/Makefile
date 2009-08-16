# New ports collection makefile for:	p5-DateTime-Format-IBeat
# Date created:	   3 october 2003
# Whom:		   mat
#
# $FreeBSD$
#

PORTNAME=	DateTime-Format-IBeat
PORTVERSION=	0.16.1
DISTVERSION=	${PORTVERSION:C/\.(.)$/\1/}
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Format times in .beat notation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		DateTime::Format::IBeat.3

.include <bsd.port.mk>

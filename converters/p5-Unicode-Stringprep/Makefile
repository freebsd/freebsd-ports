# New ports collection makefile for:	p5-Unicode-Stringprep
# Date created:				10 Dec 2010
# Whom:					Timur Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	Unicode-Stringprep
PORTVERSION=	1.103
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Preparation of Internationalized Strings (RFC 3454)

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Unicode/Normalize.pm:${PORTSDIR}/textproc/p5-Unicode-Normalize
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Unicode::Stringprep.3 Unicode::Stringprep::_Common.3 \
		Unicode::Stringprep::Prohibited.3 Unicode::Stringprep::Unassigned.3 \
		Unicode::Stringprep::Mapping.3 Unicode::Stringprep::BiDi.3

.include <bsd.port.mk>

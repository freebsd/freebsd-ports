# New ports collection makefile for:	lang/p5-Switch
# Date created:				26 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Switch
PORTVERSION=	2.02
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/DCONWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

BUILD_DEPENDS=  ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Filter/Util/Call.pm:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS=    ${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Switch.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>

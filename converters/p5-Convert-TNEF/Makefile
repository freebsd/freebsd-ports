# New ports collection makefile for:    p5-Convert-TNEF
# Date created:                         Nov 14 2000
# Whom:                                 roman@xpert.com
#
# $FreeBSD$
#

PORTNAME=	Convert-TNEF
PORTVERSION=	0.17
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Convert
PKGNAMEPREFIX=	p5-

MAINTAINER=	roman@xpert.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes	

MAN3=		Convert::TNEF.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>

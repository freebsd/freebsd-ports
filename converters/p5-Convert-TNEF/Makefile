# New ports collection makefile for:    p5-Convert-TNEF
# Date created:                         Nov 14 2000
# Whom:                                 roman@xpert.com
#
# $FreeBSD$
#

PORTNAME=	Convert-TNEF
PORTVERSION=	0.17
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Perl module to read TNEF files

BUILD_DEPENDS=	${SITE_PERL}/IO/Wrap.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/MIME/Body.pm:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Convert::TNEF.3

.include <bsd.port.mk>

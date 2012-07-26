# New ports collection makefile for:    p5-Convert-TNEF
# Date created:                         Nov 14 2000
# Whom:                                 roman@xpert.com
#
# $FreeBSD$
#

PORTNAME=	Convert-TNEF
PORTVERSION=	0.18
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to read TNEF files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-MIME-Tools>=4.109:${PORTSDIR}/mail/p5-MIME-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Convert::TNEF.3

.include <bsd.port.mk>

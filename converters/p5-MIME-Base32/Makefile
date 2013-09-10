# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	MIME-Base32
PORTVERSION=	1.02a
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl5 module for Base32 encodings

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME}-1.02
USES=		perl5
USE_PERL5=	configure

MAN3=		MIME::Base32.3

post-extract:
	@${RM} ${WRKSRC}/test1.pl

.include <bsd.port.mk>

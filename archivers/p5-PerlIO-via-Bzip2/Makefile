# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	PerlIO-via-Bzip2
PORTVERSION=	0.02
CATEGORIES=	archivers perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to provide a PerlIO layer to bzip2/bunzip2

BUILD_DEPENDS=	p5-Compress-Bzip2>=0:${PORTSDIR}/archivers/p5-Compress-Bzip2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		PerlIO::via::Bzip2.3

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	cpan-upload-http
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRADFITZ

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl script to upload one or more files to CPAN, using PAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-AppConfig-Std>=1.05:devel/p5-AppConfig-Std \
	p5-libwww>0:www/p5-libwww \
	p5-Term-ReadKey>0:devel/p5-Term-ReadKey

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

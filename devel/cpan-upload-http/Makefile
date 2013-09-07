# $FreeBSD$

PORTNAME=	cpan-upload-http
PORTVERSION=	2.4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRADFITZ

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl script to upload one or more files to CPAN, using PAUSE

RUN_DEPENDS=	\
	p5-AppConfig-Std>=1.05:${PORTSDIR}/devel/p5-AppConfig-Std \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Term-ReadKey>0:${PORTSDIR}/devel/p5-Term-ReadKey
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	cpan-upload-http.1

.include <bsd.port.mk>

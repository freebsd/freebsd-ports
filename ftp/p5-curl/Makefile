# Created by: Jason Harris <jharris@widomaker.com>
# $FreeBSD$

PORTNAME=	p5-curl
PORTVERSION=	4.15
CATEGORIES=	ftp www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/S/SZ/SZBALINT
DISTNAME=	WWW-Curl-${PORTVERSION}${EXTRACT_SUFFIX}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to libcurl

LICENSE=	ART10

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl

PERL_CONFIGURE=	yes

MAN3=		WWW::Curl.3

.include <bsd.port.mk>

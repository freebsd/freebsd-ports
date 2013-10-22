# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	libmp3-archive-perl
PORTVERSION=	0.9
CATEGORIES=	audio perl5
MASTER_SITES=	http://erislabs.net/ianb/projects/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module to manipulate filenames containing music metadata

LICENSE=	GPLv2

USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALLSYSCONFDIR/ s|/etc|${PREFIX}&|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

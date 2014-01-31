# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Memcached-libmemcached
PORTVERSION=	0.44.06
CATEGORIES=	databases devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TIMB
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Thin fast full interface to the libmemcached client API

USES=		perl5
USE_PERL5=	configure
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/my $$configure_args/ s|--disable-shared|& --without-memcached --disable-dtrace|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

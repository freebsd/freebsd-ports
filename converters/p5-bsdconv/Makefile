# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	11.1.0
PORTREVISION=	1
CATEGORIES=	converters perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LICENSE=	ISCL

LIB_DEPENDS=	libbsdconv.so:${PORTSDIR}/converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	perl-${PORTNAME}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

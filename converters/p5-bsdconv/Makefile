# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bsdconv
PORTVERSION=	11.1.0
CATEGORIES=	converters perl5
PKGNAMEPREFIX=	p5-
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	Perl wrapper for bsdconv

LICENSE=	BSD

LIB_DEPENDS=	libbsdconv.so:${PORTSDIR}/converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	75fa7e2
GH_PROJECT=	perl-${PORTNAME}

NO_STAGE=	yes
USES=		perl5
USE_PERL5=	configure

MAN3=		bsdconv.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

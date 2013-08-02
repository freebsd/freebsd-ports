# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	Tk-JPEG-Lite
PORTVERSION=	2.01403
PORTREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Very simplistic image viewer that loads JPEG images

BUILD_DEPENDS=	p5-Tk>=0:${PORTSDIR}/x11-toolkits/p5-Tk
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=	tkjpeg-lite.1
MAN3=	Tk::JPEG::Lite.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|tkjpeg|tkjpeg-lite|g' \
		${WRKSRC}/Makefile.PL ${WRKSRC}/MANIFEST
	@${MV} ${WRKSRC}/tkjpeg ${WRKSRC}/tkjpeg-lite

.include <bsd.port.mk>

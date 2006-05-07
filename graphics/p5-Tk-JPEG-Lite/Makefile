# New ports collection makefile for:	p5-Tk-JPEG-Lite
# Date created:		2004-07-23
# Whom:			Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	Tk-JPEG-Lite
PORTVERSION=	2.01403
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very simplistic image viewer that loads JPEG images

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	tkjpeg-lite.1
MAN3=	Tk::JPEG::Lite.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		-e 's|tkjpeg|tkjpeg-lite|g' \
		${WRKSRC}/Makefile.PL ${WRKSRC}/MANIFEST
	@${MV} ${WRKSRC}/tkjpeg ${WRKSRC}/tkjpeg-lite

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		needs Perl 5.8.0 or greater, please upgrade your Perl
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	imageindex
# Date created:				Sat Sep  7 15:53:33 MST 2002
# Whom:					John Reynolds <johnjen@reynoldsnet.org>
#
# $FreeBSD$
#

PORTNAME=	imageindex
PORTVERSION=	1.0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.edwinh.org/imageindex/release/ \
		http://www.reynoldsnet.org/imageindex/release/

MAINTAINER=	johnjen@reynoldsnet.org
COMMENT=	A digital photo gallery tool

RUN_DEPENDS=	\
	${LOCALBASE}/bin/Magick-config:${PORTSDIR}/graphics/ImageMagick \
	${LOCALBASE}/bin/wrjpgcom:${PORTSDIR}/graphics/jpeg \
	${SITE_PERL}/Image/Info.pm:${PORTSDIR}/graphics/p5-Image-Info

USE_REINPLACE=	yes

MAN1=	imageindex.1

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man| ;' ${WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

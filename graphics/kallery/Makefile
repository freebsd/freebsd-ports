# New ports collection makefile for:   kallery
# Date created:        22 September 2002
# Whom:                Michael Collette
#
# $FreeBSD$
#

PORTNAME=	kallery
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	graphics kde
MASTER_SITES=	http://www.virtualartisans.com/kde/andras/kallery/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		metrol@metrol.net
COMMENT=	An image gallery generator for KDE

LIB_DEPENDS=	Magick.7:${PORTSDIR}/graphics/ImageMagick

BROKEN=		Checksum mismatch

USE_KDELIBS_VER=3
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Configure fails on amd64"
.endif

post-patch:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee \
		's|(dtd/kdex.dtd)|${LOCALBASE}/share/apps/ksgmltools2/customization/\1|' \
		${WRKSRC}/doc/en/index.docbook
.else
	@${REINPLACE_CMD} -Ee 's|(kallery po) doc|\1|' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>

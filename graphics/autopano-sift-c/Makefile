# New ports collection makefile for:	autopano-sift-c
# Date created:		10 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autopano-sift-C
PORTVERSION=	2.5.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Automatic panorama control point generation tool, C port

RESTRICTED=	May be covered by patents

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		pano13:${PORTSDIR}/graphics/libpano13

CONFLICTS=	autopano-sift-[0-9]*

USE_GNOME=	libxml2
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/autopano bin/autopano-c-complete.sh \
		bin/autopano-sift-c bin/generatekeys

PORTDOCS=	*

MAN1=		autopano-c-complete.1 autopano.1 generatekeys.1
MAN7=		autopano-sift-c.7

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/CMakeLists.txt

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${DOCSDIR}/
.endif

.include <bsd.port.mk>

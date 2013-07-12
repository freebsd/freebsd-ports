# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autopano-sift-C
PORTVERSION=	2.5.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/hugin/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Automatic panorama control point generation tool, C port

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		pano13:${PORTSDIR}/graphics/libpano13

RESTRICTED=	May be covered by patents

CONFLICTS=	autopano-sift-[0-9]*

USE_GNOME=	libxml2
USES=		cmake
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/autopano bin/autopano-c-complete.sh \
		bin/autopano-sift-c bin/generatekeys

PORTDOCS=	*

MAN1=		autopano-c-complete.1 autopano.1 generatekeys.1
MAN7=		autopano-sift-c.7

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${DOCSDIR}/
.endif

.include <bsd.port.mk>

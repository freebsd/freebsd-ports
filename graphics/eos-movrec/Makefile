# $FreeBSD$
# Created by:	Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	eos-movrec
DISTVERSION=	0.3.1_beta
PORTREVISION=	2
CATEGORIES=	graphics multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.3_beta/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Capture short movies with Canon DSLR camera

LICENSE=	GPLv2

LIB_DEPENDS=	gphoto2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	pnmtopng:${PORTSDIR}/graphics/netpbm

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build gui

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
DISTVERSIONSUFFIX=	-src

PLIST_FILES=	bin/eos_movrec \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES=	"EOS Camera Movie Record" "${COMMENT}" "${PORTNAME}" \
			"${PORTNAME:S/-/_/}" "Application;Graphics;" ${FALSE}

post-patch:
	@${REINPLACE_CMD} -e 's,GLIBC,${OPSYS},' ${WRKSRC}/os_api.h

post-build:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/winicontoppm -bestqual eos-movrec2.ico | \
		${LOCALBASE}/bin/pnmtopng > eos-movrec.png)

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>

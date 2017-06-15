# $FreeBSD$

PORTNAME=	acoustid-fingerprinter
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	AcoustID audio fingerprint submission tool

LICENSE=	GPLv2

LIB_DEPENDS=	libchromaprint.so:audio/chromaprint \
		libtag.so:audio/taglib \
		libavcodec.so:multimedia/ffmpeg

USES=		cmake desktop-file-utils
USE_QT4=	corelib gui network \
		qmake_build moc_build rcc_build uic_build
USE_GITHUB=	yes
GH_ACCOUNT=	acoustid
GH_TAGNAME=	632e879

INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		 ${WRKSRC}/cmake/modules/*.cmake

post-install:
.for i in 16 24 32 48 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	${INSTALL_DATA} ${WRKSRC}/images/acoustid-fp-${i}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/acoustid-fingerprinter.png
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/images/acoustid-fingerprinter.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>

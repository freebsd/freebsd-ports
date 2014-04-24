# Created by: cy
# $FreeBSD$

PORTNAME=	qxv
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES+=	graphics
MASTER_SITES=	http://labs.freehackers.org/attachments/download/422/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Qt 4 program that displays images of various formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libicui18n.so:${PORTSDIR}/devel/icu \
		libintl.so:${PORTSDIR}/devel/gettext \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES=		iconv qmake
USE_BZIP2=	yes
USE_XORG=	sm xrender xext x11 xau xdmcp ice xcb
USE_QT4=	corelib gui moc_build uic_build rcc_build
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>

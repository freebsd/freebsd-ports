# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	kaudiocreator
PORTVERSION=	1.3
PORTREVISION=	4
CATEGORIES=	audio kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
DISTNAME=	107645-${PORTNAME}-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Audio-cd ripper and encoder for KDE4

LICENSE=	GPLv2

LIB_DEPENDS=	libdiscid.so:audio/libdiscid \
		libtag.so:audio/taglib
RUN_DEPENDS=	flac:audio/flac \
		oggenc:audio/vorbis-tools
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	lame:audio/lame
.endif

USES=		cmake tar:bzip2
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 libkcddb libkcompactdisc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

post-patch-NLS-off:
	${REINPLACE_CMD} 's,add_subdirectory(po),,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>

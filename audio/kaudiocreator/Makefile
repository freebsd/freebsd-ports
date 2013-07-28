# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	kaudiocreator
PORTVERSION=	1.3
CATEGORIES=	audio kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
DISTNAME=	107645-${PORTNAME}-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Audio-cd ripper and encoder for KDE4

LICENSE=	GPLv2

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		tag:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

USE_BZIP2=	yes
USES=		cmake
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix libkcddb libkcompactdisc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "

post-patch:
	${REINPLACE_CMD} 's,add_subdirectory(po),,' ${WRKSRC}/CMakeLists.txt

.endif

.include <bsd.port.mk>

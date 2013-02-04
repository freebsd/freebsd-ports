# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	kaudiocreator
PORTVERSION=	1.2.90
PORTREVISION=	6
CATEGORIES=	audio kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
DISTNAME=	107645-${PORTNAME}-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Audio-cd ripper and encoder for KDE4

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		tag:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix libkcddb

LICENSE=	GPLv2
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

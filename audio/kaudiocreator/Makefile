# New ports collection makefile for:	kaudiocreator
# Date created:				2011/01/01
# Whom:					David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$

PORTNAME=	kaudiocreator
PORTVERSION=	1.2.90
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	http://kde-look.org/CONTENT/content-files/
DISTNAME=	107645-${PORTNAME}-${PORTVERSION}

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	An audio-cd ripper and encoder for KDE4

LIB_DEPENDS=	discid:${PORTSDIR}/audio/libdiscid \
		tag:${PORTSDIR}/audio/taglib \
		kcddb:${PORTSDIR}/multimedia/kdemultimedia4
RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac \
		oggenc:${PORTSDIR}/audio/vorbis-tools
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdeprefix

LICENSE=	GPLv2
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

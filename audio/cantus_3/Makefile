# New ports collection makefile for:	cantus_3
# Date created:				18 May 2004
# Whom:					asa@gascom.ru
#
# $FreeBSD$
#

PORTNAME=	cantus_3
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.gascom.ru/pub/asa/ \
		http://web222.mis02.de/releases/cantus_3/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	asa@gascom.ru
COMMENT=	Tool for tagging and renaming MP3 and OGG/Vorbis files

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2 \
		glademm-2.0.1:${PORTSDIR}/devel/libglademm \
		ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		Does not build on 4.X.
.endif

BASH?=		${LOCALBASE}/bin/bash

do-build:
	@cd ${WRKSRC} && ${BASH} build.sh --prefix '${PREFIX}'

do-install:
	@cd ${WRKSRC} && ${BASH} build.sh --install --prefix '${PREFIX}'

.include <bsd.port.post.mk>

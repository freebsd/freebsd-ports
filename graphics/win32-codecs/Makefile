# New ports collection makefile for:	avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	win32-codecs
PORTVERSION=	${CODEC_VERSION}
CATEGORIES=	graphics audio
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/ \
		http://divx.euro.ru/ \
		http://www.toon.eu.org/divx/
DISTFILES=	binaries-${CODEC_VERSION}.zip \
		wmvds32.ax.gz
EXTRACT_ONLY=	binaries-${CODEC_VERSION}.zip

MAINTAINER=	holger@eit.uni-kl.de

RESTRICTED=	Unsure of codec\'s license

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

CODEC_VERSION=	010122
# Used by other ports to detect if this is installed
CODEC_DETECTION_FILE=	${LOCALBASE}/lib/win32/wmvds32.ax

post-extract:
	@${GZCAT} ${DISTDIR}/wmvds32.ax.gz > ${WRKDIR}/wmvds32.ax

do-install:
	@${MKDIR} ${PREFIX}/lib/win32
	@${CHMOD} 0555 ${PREFIX}/lib/win32
	@${INSTALL_DATA} ${WRKDIR}/* ${PREFIX}/lib/win32

.include <bsd.port.mk>

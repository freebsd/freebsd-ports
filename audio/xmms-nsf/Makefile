# New ports collection makefile for:	xmms-nsf
# Date created:				18 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	xmms-nsf
PORTVERSION=	0.0.3
CATEGORIES=	audio
MASTER_SITES=	http://optronic.sourceforge.net/files/ \
		http://critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS input-plugin for playing Nintendo(TM) NSF audio files

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_AUTOTOOLS=	libtool:13
USE_X_PREFIX=	yes

ONLY_FOR_ARCHS=	i386 amd64

CFLAGS+=	-fPIC

PLIST_FILES=	lib/xmms/Input/libnsf.so lib/xmms/Input/libnsf.la

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/nes/nestypes.h

post-install:
	@${SED} -e 's|%%VERSION%%|${PORTVERSION}|' ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	xmms-arts
# Date created:				12 Nov 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-arts
PORTVERSION=	0.6.0
CATEGORIES=	audio
MASTER_SITES=	http://havardk.xmms.org/plugins/arts_output/
DISTNAME=	arts_output-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aRts output plugin for XMMS.

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		artsc.0:${PORTSDIR}/audio/arts

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		<${FILESDIR}/pkg-message.in >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

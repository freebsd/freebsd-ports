# New ports collection makefile for:	xmms-arts
# Date created:				12 Nov 2003
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-arts
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://stukach.com/hosted/m.i.a/xmmsarts/
DISTNAME=	${PORTNAME:S/-//}-${PORTVERSION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	aRts output plugin for XMMS.

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		artsc.0:${PORTSDIR}/audio/arts

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${X11BASE}/include"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		<${FILESDIR}/pkg-message.in >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	vertex
# Date created:				1 June 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vertex
PORTVERSION=	0.1.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/${DISTNAME}/vertex

IMLIB_CONFIG?=	${X11BASE}/bin/imlib-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GTK=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		IMLIB_CONFIG="${IMLIB_CONFIG}"
INSTALL_TARGET=	vertex_install

MAN1=		${PORTNAME}.1

pre-patch:
	@${FIND} ${WRKSRC} -name "*.[c,h]" | ${XARGS} ${PERL} -pi -e \
		's|malloc.h|stdlib.h|'

.include <bsd.port.mk>

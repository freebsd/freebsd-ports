# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	editor
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.defora.org/os/download/download/4326/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Editor-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop text editor

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		docbook-xsl>=0:textproc/docbook-xsl

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop

MAKE_ARGS=	PREFIX=${PREFIX}
USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtk20

MANDIRS=	${PREFIX}/share/man/man1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/editor \
		${STAGEDIR}${PREFIX}/bin/filter

.include <bsd.port.mk>

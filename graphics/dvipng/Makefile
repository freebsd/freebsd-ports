# ex:ts=8
# Ports collection makefile for:	dvipng
# Date created:			Dec 9, 2003
# Whom:				o_sleep
#
# $FreeBSD$
#

PORTNAME=	dvipng
PORTVERSION=	0.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	preview-latex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI to PNG Converter

BUILD_DEPENDS=	kpsepath:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

INFO=		dvipng

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>

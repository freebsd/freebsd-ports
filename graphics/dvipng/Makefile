# ex:ts=8
# Ports collection makefile for:	dvipng
# Date created:			Dec 9, 2003
# Whom:				o_sleep
#
# $FreeBSD$
#

PORTNAME=	dvipng
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	preview-latex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DVI to PNG Converter

BUILD_DEPENDS=	kpsepath:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		dvipng
PLIST_FILES=	bin/dvipng

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/dvipng

.include <bsd.port.mk>

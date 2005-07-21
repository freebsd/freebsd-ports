# New ports collection makefile for:	icoutils
# Date created:				Sun Jun 12 10:19:46 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icoutils
PORTVERSION=	0.26.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lintl"

MAN1=		extresso.1 genresscript.1 icotool.1 wrestool.1

PLIST_FILES=	\
		bin/extresso \
		bin/genresscript \
		bin/icotool \
		bin/wrestool

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>

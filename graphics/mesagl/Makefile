# New ports collection makefile for:    Mesa
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	Mesa
PORTVERSION=	3.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${PORTVERSION}${EXTRACT_SUFX} \
		MesaDemos-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jseger@FreeBSD.org

USE_BZIP2=	yes

.if defined(WANT_GGI)
LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--with-ggi=${LOCALBASE}
.endif

GLVER=		14
GLUTVER=	3
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"
PLIST_SUB=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"

post-install:
.for lib in GL GLU
	@${LN} -sf ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/libMesa${lib}.so
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:    Mesa
# Date created:         Tue Feb  7 12:02:49  1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	Mesa
PORTVERSION=	3.1
CATEGORIES=	graphics
MASTER_SITES= 	http://download.sourceforge.net/mesa3d/ \
		ftp://iris.ssec.wisc.edu/pub/Mesa/ \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
DISTFILES=	MesaLib-${PORTVERSION}${DISTNAME}${EXTRACT_SUFX} \
		MesaDemos-${VERSION}.tar.gz

MAINTAINER=	jseger@FreeBSD.org

.if defined(WANT_GGI)
LIB_DEPENDS=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--with-ggi=${LOCALBASE}
.endif

GLVER=		14
GLUTVER=	3
WRKSRC=		${WRKDIR}/${PKGNAME}
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"
PLIST_SUB=	GLVER="${GLVER}" GLUTVER="${GLUTVER}"

post-install:
.for lib in GL GLU
	@${LN} -sf ${PREFIX}/lib/lib${lib}.so ${PREFIX}/lib/libMesa${lib}.so
.endfor

.include <bsd.port.mk>

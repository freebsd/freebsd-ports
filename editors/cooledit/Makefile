# New ports collection makefile for:	 cooledit
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	cooledit
PORTVERSION=	3.17.17
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X/cooledit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of utilities, including a GUI editor

USE_XLIB=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		cooledit.1 coolman.1 smalledit.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
CFLAGS+=	-DHAVE_MBRTOWC
.endif

.if defined(WITH_NEXT_LOOK)
CONFIGURE_ARGS+=	--enable-NeXT-look
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|po pixmap man|po man|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

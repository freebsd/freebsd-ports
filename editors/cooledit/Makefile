# New ports collection makefile for:	 cooledit
# Date created:		18 November 1997
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	cooledit
PORTVERSION=	3.17.17
PORTREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/X/cooledit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of utilities, including a GUI editor

USE_AUTOTOOLS=	libtool:22
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11 xt
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

MAN1=		cooledit.1 coolman.1 smalledit.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CFLAGS+=	-DHAVE_MBRTOWC

.if defined(WITH_NEXT_LOOK)
CONFIGURE_ARGS+=	--enable-NeXT-look
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|po pixmap man|po man|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

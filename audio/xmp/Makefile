# New ports collection makefile for: 	xmp
# Date created:		18 September 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmp
PORTVERSION=	2.0.4
CATEGORIES=	audio
MASTER_SITES=	http://xmp.helllabs.org/pkg/%SUBDIR%/ \
		http://xmp.linuxave.net/pkg/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	anders@fix.no

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" CFLAGS="-I${LOCALBASE}/include"
USE_AUTOCONF=	yes
WANT_ESOUND=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500013
USE_ESOUND=	yes
CONFIGURE_ARGS+=	--disable-oss --enable-esd
.elif defined(HAVE_ESOUND)
USE_ESOUND=	yes
CONFIGURE_ARGS+=	--enable-esd
.endif

MAN1=		xmp.1
MLINKS=		xmp.1 xxmp.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/docs/xmp.1

.include <bsd.port.post.mk>

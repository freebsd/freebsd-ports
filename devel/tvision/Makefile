# New ports collection makefile for:	tvision
# Date created:				16 February 1997
# Whom:					Sandro Sigala
#
# $FreeBSD$
#

PORTNAME=	tvision
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.sigala.it/sergio/tvision/mysource/
MASTER_SITE_SUBDIR=	devel/lang/c++

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

post-extract:
	@${MV} ${WRKSRC}/myendian.h ${WRKSRC}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,myendian.h,tvision/myendian.h,g' \
		${WRKSRC}/lib/drawbuf.h ${WRKSRC}/lib/system.h
	@${REINPLACE_CMD} -e 's,menus.h msgbox.h,menus.h msgbox.h myendian.h,' \
		${WRKSRC}/lib/Makefile.in

.include <bsd.port.post.mk>

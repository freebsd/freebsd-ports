# New ports collection makefile for:	liboil
# Date created:				Nov 24, 2004
# Whom:					ijliao
#
# $FreeBSD$
#    $MCom: ports/devel/liboil/Makefile,v 1.7 2008/03/23 06:57:57 marcus Exp $
#      $Id: Makefile 23 2006-10-25 14:24:32Z buhnux $

PORTNAME=	liboil
PORTVERSION=	0.3.15
CATEGORIES=	devel
MASTER_SITES=	http://liboil.freedesktop.org/download/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library of optimized inner loops

USE_GNOME=	pkgconfig gnomehack gnometarget ltverhack
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--disable-glib
CFLAGS:=	${CFLAGS:N-O*} -O2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000 && !defined(WITH_3DNOW_GCC40)
BUILD_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
RUN_DEPENDS+=	gcc34:${PORTSDIR}/lang/gcc34
CC:=	gcc34
CXX:=	g++34
.endif

.if defined(WITH_3DNOW_GCC40) && ${OSVERSION} < 700042
USE_GCC=	4.1+
.if ${OSVERSION} < 600000
RUN_DEPENDS+=	${BUILD_DEPENDS}
.endif
.endif

pre-everything::
.if ${MACHINE_CPU:M3dnow}!="" && ${OSVERSION} < 700042
.if !defined(WITH_3DNOW_GCC40)
	@${ECHO_MSG} "You can enable 3dnow extensions by defining"
	@${ECHO_MSG} "WITH_3DNOW_GCC40=yes"
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Note: ${PORTNAME} will depend on gcc4.0+ with WITH_3DNOW_GCC40"
	@${ECHO_MSG} "defined."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\\$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint\.h|<inttypes.h|g' \
		${WRKSRC}/liboil/liboiltypes.h \
		${WRKSRC}/liboil/liboilprofile.h \
		${WRKSRC}/liboil/liboil.h

.include <bsd.port.post.mk>

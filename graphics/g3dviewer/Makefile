# ex:ts=8
# Ports collection makefile for:	g3dviewer
# Date created:			May 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	g3dviewer
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://automagically.de/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 3D file viewer for GTK+

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_GNOME=	gnometarget gtk20
USE_GL=		gl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		g3dviewer.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|DBG_CFLAGS="-O2"|DBG_CFLAGS=""|g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>

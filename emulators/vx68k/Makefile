# ex:ts=8
# Ports collection makefile for:	vx68k
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vx68k
PORTVERSION=	1.1.10
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.hypercore.co.jp/vx68k/${PORTNAME}-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A virtual machine that emulates a Sharp X68000

LIB_DEPENDS=	vm68k.4:${PORTSDIR}/emulators/libvm68k

USE_GL=		yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
LIBTOOLFILES=	configure vx68k-gtk/configure
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	vx68k.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU \
		${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,Bison ,Bison,g" ${WRKSRC}/vx68k-gtk/configure

.include <bsd.port.post.mk>

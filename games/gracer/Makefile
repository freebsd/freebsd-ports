# New ports collection makefile for:   gracer
# Date created:        Fri Jul 30 20:50:16 MET DST 1999
# Whom:                nox@jelal.kn-bremen.de
#
# $FreeBSD$
#

PORTNAME=	gracer
PORTVERSION=	0.1.5
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	nox@FreeBSD.org
COMMENT=	A 3D motor sport simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tcl84.1:${PORTSDIR}/lang/tcl84

USE_GL=		glut
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	autoconf213
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl8.4
USE_GMAKE=	yes
# for plib (sound):
CONFIGURE_ARGS+=	--with-plib=${LOCALBASE}/plib

MAN6=		gracer.6

.include <bsd.port.pre.mk>

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/common/gr_memory.h

.include <bsd.port.post.mk>

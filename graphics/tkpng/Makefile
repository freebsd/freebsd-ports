# New ports collection makefile for:	tkpng
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkpng
PORTVERSION=	0.7
CATEGORIES=	graphics tk84
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	PNG support for Tcl/Tk

USE_TK=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl${TK_VER} \
		--with-tk=${LOCALBASE}/lib/tk${TK_VER} \
		--with-tclinclude=${LOCALBASE}/include/tcl${TK_VER}/generic \
		--with-tkinclude=${LOCALBASE}/include/tk${TK_VER}/generic \
		--exec-prefix=${PREFIX} --enable-shared
CPPFLAGS=	-I${LOCALBASE}/include/tk${TK_VER}/generic -I${X11BASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG} TKLIBVER=${TKLIBVER}
USE_LDCONFIG=	${PREFIX}/lib/${TKPKG}
WRKSRC=		${WRKDIR}/${TKPKG}

post-install:
	@${LN} -sf ${PREFIX}/lib/${TKPKG}/lib${TKPKG}.so \
		${PREFIX}/lib/${TKPKG}/lib${TKPKG}.so.0

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not compile on 4.x
.endif

.include <bsd.port.post.mk>

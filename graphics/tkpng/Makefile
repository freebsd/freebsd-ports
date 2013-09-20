# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkpng
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics tk
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PNG support for Tcl/Tk

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/license.terms

USE_TK=		84+
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tk=${TK_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}/generic \
		--with-tkinclude=${TK_INCLUDEDIR}/generic \
		--exec-prefix=${PREFIX} --enable-shared
CPPFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${LOCALBASE}/include
TKPKG=		${PORTNAME}${PORTVERSION}
PLIST_SUB=	VER=${PORTVERSION} TKPKG=${TKPKG} TKLIBVER=${TKLIBVER}

.include <bsd.port.post.mk>

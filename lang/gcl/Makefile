# Created by: hsu
# $FreeBSD$

PORTNAME=	gcl
PORTVERSION=	2.6.7
PORTREVISION=	7
CATEGORIES=	lang tcl tk
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Common Lisp

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

ONLY_FOR_ARCHS=	i386

USES=		readline gmake tk
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--prefix=${PREFIX} \
	--enable-ansi \
	--enable-machine=FreeBSD \
	--enable-info=${PREFIX}/info \
	--enable-tkconfig=${TK_LIBDIR} \
	--enable-tclconfig=${TCL_LIBDIR} \
	--with-x \
	--disable-dlopen \
	--disable-dynsysbfd \
	--disable-statsysbfd \
	--disable-locbfd \
	--enable-custreloc
CONFIGURE_ENV=	C_INCLUDE_PATH="${PREFIX}/include" LIBRARY_PATH="${PREFIX}/lib"
MAKEFILE=	makefile
MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-I${LOCALBASE}/include

PLIST_SUB=	GCL_VER="${PORTVERSION}"

INFO=		gcl-si gcl-tk

NO_STAGE=	yes
post-patch::
	@${REINPLACE_CMD} -e \
		's|@@CFLAGS@@|${CFLAGS} -I${LOCALBASE}/include| ; \
		 s|@@LOCALLIBS@@|-lreadline -lm -L${LOCALBASE}/lib -lgmp|' \
			${WRKSRC}/h/FreeBSD.defs

.include <bsd.port.mk>

# New ports collection makefile for:	XaraLX
# Date created:				22 Mar 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XaraLX
PORTVERSION?=	0.5r1175
PORTREVISION?=	2
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.xara.com/opensource/
DISTFILES?=	${PORTNAME}Src-${PORTVERSION}.tar.bz2

MAINTAINER=	vd@FreeBSD.org
COMMENT?=	Top-tier vector/general purpose graphics program (recommended version)

USE_BZIP2=	yes
USE_X_PREFIX=	yes

#WXDEP=	${X11BASE}/libwx_baseu-2.6.so.0.3.1
WXDEP=	wxgtk2-unicode>=2.6.3
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config \
		${WXDEP}:${PORTSDIR}/x11-toolkits/wxgtk26-unicode \
		xml2-config:${PORTSDIR}/textproc/libxml2 \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS+=	${WXDEP}:${PORTSDIR}/x11-toolkits/wxgtk26-unicode
LIB_DEPENDS+=	dlmalloc.2:${PORTSDIR}/devel/libdlmalloc \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	autoconf:259:env aclocal:19:env automake:19:env libtool:15:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-wx-config=wxgtk2u-2.6-config \
		--program-suffix=${PKGNAMESUFFIX}
CONFIGURE_ENV+=	CPPFLAGS_APPEND="-I${LOCALBASE}/include/atk-1.0/atk \
		-I${X11BASE}/include/gtk-2.0/gtk"
# we're using dlmalloc because the stock libc does not have malloc_usable_size()
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -ldlmalloc"

USE_GMAKE=	yes
# add wxOil with -I- appended to it before any other -I stuff, see below
MAKE_ENV?=	INCLUDES="-I../wxOil -I- -I${LOCALBASE}/include/dlmalloc"

USE_GCC=	3.4+

MAN1=	xaralx${PKGNAMESUFFIX}.1

.if !defined(NOPORTDOCS)
DOCS_IN_WRKSRC=	AUTHORS GPL LICENSE README
DOCS_IN_DOC=	en/xaralx.htm gifutil.txt mtrand.txt
PORTDOCS=	${DOCS_IN_WRKSRC} en ${DOCS_IN_DOC:M*.txt}
.endif

# make non-conflicting with the slave port
DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

PIXMAPSDIR=	${PREFIX}/share/pixmaps

# directories with .xar files
XARDIRS=	Designs Templates

PLIST_SUB+=	PKGNAMESUFFIX=${PKGNAMESUFFIX} \
		DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||} \
		PIXMAPSDIR=${PIXMAPSDIR:S|^${PREFIX}/||}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64" && ${ARCH} != "powerpc"
BROKEN=	does not configure due to the lack of CDraw libraries for ${ARCH}
.endif

.if !defined(PKGNAMESUFFIX)
# we need to strip wxOil from the include path because it contains file
# named strings.h which when included by /usr/include/string.h results
# in a complete mess
post-patch:
	${REINPLACE_CMD} -E -e 's|-I[^[:space:]]*/wxOil[[:space:]]||g' \
		${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -E -e 's/^CHECKSUM = md5sum$$/CHECKSUM = md5/' \
		${WRKSRC}/wxOil/Makefile.am
	${REINPLACE_CMD} -E \
		-e 's/^Name=Xara LX$$/Name=Xara LX ${PORTVERSION}/' \
		${WRKSRC}/xaralx.desktop
.else
post-patch:
	${REINPLACE_CMD} -E \
		-e 's/^Name=Xara LX$$/Name=Xara LX ${PORTVERSION}/' \
		-e 's/^Icon=xaralx.png$$/Icon=xaralx${PKGNAMESUFFIX}.png/' \
		-e 's/^FilePattern=xaralx;$$/FilePattern=xaralx${PKGNAMESUFFIX}/' \
		-e 's/^Exec=xaralx %F$$/Exec=xaralx${PKGNAMESUFFIX} %F/' \
		-e 's/^TryExec=xaralx$$/TryExec=xaralx${PKGNAMESUFFIX}/' \
		${WRKSRC}/xaralx.desktop
.endif

pre-configure:
	cd ${WRKSRC} && \
	${SETENV} ${AUTOTOOLS_ENV} \
	ACLOCAL="${ACLOCAL} -I ${LOCALBASE}/share/aclocal" \
	${AUTORECONF} -f -i -s

.if !target(do-install)
do-install:
	${MKDIR} ${DESKTOPDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/XaraLX \
		${PREFIX}/bin/xaralx${PKGNAMESUFFIX}
	${INSTALL_DATA} ${WRKSRC}/xaralx.desktop \
		${DESKTOPDIR}/xaralx${PKGNAMESUFFIX}.desktop
	${INSTALL_DATA} ${WRKSRC}/xaralx.png \
		${PIXMAPSDIR}/xaralx${PKGNAMESUFFIX}.png
.for xardir in ${XARDIRS}
	${MKDIR} ${EXAMPLESDIR}/${xardir}
	${INSTALL_DATA} ${WRKSRC}/${xardir}/*.xar ${EXAMPLESDIR}/${xardir}/
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/XaraLX.1 \
		${MANPREFIX}/man/man1/xaralx${PKGNAMESUFFIX}.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/en
.for d in ${DOCS_IN_WRKSRC}
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}/${d}
.endfor
.for d in ${DOCS_IN_DOC}
	${INSTALL_DATA} ${WRKSRC}/doc/${d} ${DOCSDIR}/${d}
.endfor
.endif
.endif

.include <bsd.port.post.mk>

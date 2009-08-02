# New ports collection makefile for:	XaraLX
# Date created:				22 Mar 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XaraLX
PORTVERSION?=	0.7r1692
PORTREVISION?=	7
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.xara.com/opensource/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME:L}${PKGNAMESUFFIX}
DISTFILES?=	${PORTNAME}Src-${PORTVERSION}.tar.bz2

MAINTAINER=	vd@FreeBSD.org
COMMENT?=	Top-tier vector/general purpose graphics program (recommended version)

USE_BZIP2=	yes

BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config \
		xml2-config:${PORTSDIR}/textproc/libxml2 \
		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_AUTOTOOLS=	autoconf:262:env aclocal:19:env automake:19:env libtool:22:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-suffix=${PKGNAMESUFFIX}

USE_GMAKE=	yes
MAKE_ENV?=	LANG=C

USE_XORG=	x11
USE_WX=		2.6
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes

MAN1=	xaralx${PKGNAMESUFFIX}.1
MANFILE=	xaralx.1

.if !defined(NOPORTDOCS)
DOCS=	AUTHORS GPL LICENSE README doc/gifutil.txt doc/mtrand.txt \
	doc/en/LICENSE
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

ONLY_FOR_ARCHS= i386 amd64 powerpc
ONLY_FOR_ARCHS_REASON=	does not configure due to the lack of CDraw libraries for ${ARCH}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700036
# we're using ptmalloc because the stock libc does not have malloc_usable_size()
BUILD_DEPENDS+=	ptmalloc>=2.0_1:${PORTSDIR}/devel/ptmalloc
RUN_DEPENDS+=	ptmalloc>=2.0_1:${PORTSDIR}/devel/ptmalloc
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib -lptmalloc"
MAKE_ENV+=	INCLUDES="-I${LOCALBASE}/include/ptmalloc"
.else
# building with gcc 4.2 results in libKernel.a becoming 800+ MB
# and hitting the 400 MB file limit on pointyhat
NO_PACKAGE=	yes
.endif

post-patch:
	${REINPLACE_CMD} -E \
		-e 's/^Name=Xara Xtreme$$/Name=Xara Xtreme ${PORTVERSION}/' \
		-e 's/^Icon=xaralx.png$$/Icon=xaralx${PKGNAMESUFFIX}.png/' \
		-e 's/^FilePattern=xaralx;$$/FilePattern=xaralx${PKGNAMESUFFIX}/' \
		-e 's/^Exec=xaralx %F$$/Exec=xaralx${PKGNAMESUFFIX} %F/' \
		-e 's/^TryExec=xaralx$$/TryExec=xaralx${PKGNAMESUFFIX}/' \
		${WRKSRC}/xaralx.desktop
.if ${OSVERSION} >= 700036
	${REINPLACE_CMD} \
		-e 's/malloc\/malloc.h/stdlib.h/' \
		-e 's/malloc.h/stdlib.h/' \
		${WRKSRC}/wxOil/fixmem.cpp \
		${WRKSRC}/wxOil/stdwx.h
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
	${INSTALL_MAN} ${WRKSRC}/doc/${MANFILE} \
		${MANPREFIX}/man/man1/xaralx${PKGNAMESUFFIX}.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/en
.for d in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}/${d:S|^doc/||}
.endfor
	${MKDIR} ${DOCSDIR}/en/xaralxHelp
	${TAR} -C ${DOCSDIR}/en/xaralxHelp \
		-zxf ${WRKSRC}/doc/en/xaralxHelp.tar.gz
.endif
.endif

.include <bsd.port.post.mk>

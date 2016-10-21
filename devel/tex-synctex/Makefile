# $FreeBSD$

PORTNAME=	synctex
PORTVERSION=	1.17.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-20150521-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Synchronization TeXnology parser library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/synctexdir/README.txt

CONFLICTS=	tex-web2c-20150521
USES=		libtool pathfix pkgconfig tar:xz
USE_TEX=	kpathsea
USE_LDCONFIG=	yes
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux texk/web2c
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
EXCLUDE_ENGINES=etex aleph luatex luajittex pdftex mf mf-nowin ptex \
		eptex uptex euptex xetex tex otangle mp pmp upmp web2c \
		web-progs
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--with-x=no \
		--without-mf-x-toolkit \
		--with-system-zlib \
		--with-system-kpathsea
CFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

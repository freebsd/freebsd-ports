PORTNAME=	synctex
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/${TEXLIVE_YEAR}/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${TEXLIVE_VERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	Synchronization TeXnology parser library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/synctexdir/README.txt

USES=		libtool localbase pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_TEX=	kpathsea

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${EXCLUDE_ENGINES:S/^/--disable-/} \
		--with-system-kpathsea \
		--with-system-zlib \
		--with-x=no \
		--without-mf-x-toolkit

INSTALL_TARGET=	install-strip

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

EXTRACT_FILES=		build-aux texk/web2c
EXCLUDE_ENGINES=	etex aleph luatex luajittex pdftex mf mf-nowin ptex \
			eptex uptex euptex xetex tex otangle mp pmp upmp web2c \
			web-progs luahbtex luajithbtex mflua mfluajit latex \
			pdftex

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.mk>

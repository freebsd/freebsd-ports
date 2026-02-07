PORTNAME=	fmtconv
DISTVERSION=	r30
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/EleonoreMizo/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Format conversion tools for Vapoursynth and Avisynth+
WWW=		https://github.com/EleonoreMizo/fmtconv

LICENSE=	WTFPL
LICENSE_FILES=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		autoreconf compiler:c++14-lang gmake libtool zip

EXTRACT_AFTER_ARGS=	-d ${WRKDIR}/${PORTNAME}-${DISTVERSION}

WRKSRC_SUBDIR=	build/unix
PATCH_WRKSRC=	${WRKSRC:H:H}

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDOCS=	*
PLIST_FILES=	lib/vapoursynth/lib${PORTNAME}.so

CONFIGURE_ARGS=	--libdir="${PREFIX}/lib/vapoursynth"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# We need at least AVX2 instructions on amd64
.if !defined(CPUTYPE) && ${ARCH} == "amd64"
CONFIGURE_ENV+= EXTRA_CXXFLAGS=-march=haswell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/' \
		${WRKSRC}/configure.ac

post-install:
	(cd ${PATCH_WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

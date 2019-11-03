# $FreeBSD$

PORTNAME=	fmtconv
PORTVERSION=	r20
PORTREVISION=	4
CATEGORIES=	graphics
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Format conversion tools for Vapoursynth

LICENSE=	WTFPL

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VapourSynth.h:multimedia/vapoursynth

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	https://github.com/EleonoreMizo/fmtconv/issues/8

USE_GITHUB=	yes
GH_ACCOUNT=	EleonoreMizo

USES=		autoreconf compiler:c++11-lib gmake libtool pkgconfig
EXCLUDE=	VapourSynth.h *.txt
EXTRACT_AFTER_ARGS=	${EXCLUDE:S,^,--exclude ,}
WRKSRC_SUBDIR=	build/unix
PATCH_WRKSRC=	${WRKSRC:H:H}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${DATADIR}"
CPPFLAGS+=	`pkg-config vapoursynth --cflags`
INSTALL_TARGET=	install-strip
DATADIR=	${PREFIX}/lib/vapoursynth
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDATA=	lib${PORTNAME}.so
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/-O3 //' ${WRKSRC}/Makefile.am

post-install:
	(cd ${PATCH_WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

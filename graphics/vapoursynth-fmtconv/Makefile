# $FreeBSD$

PORTNAME=	fmtconv
PORTVERSION=	r22
CATEGORIES=	graphics
PKGNAMEPREFIX=	vapoursynth-

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	3b64292dd274.patch:-p1
PATCHFILES+=	5e0340d35e4d.patch:-p1
PATCHFILES+=	c62063bc34c6.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Format conversion tools for Vapoursynth

LICENSE=	WTFPL

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VapourSynth.h:multimedia/vapoursynth

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

post-install:
	(cd ${PATCH_WRKSRC}/doc && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

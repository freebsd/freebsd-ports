# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdmf
DISTVERSION=	0.0.9s
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://w140.com/audio/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find similar music by perceptual hashing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgdbm.so:databases/gdbm \
		libfftw3.so:math/fftw3
RUN_DEPENDS=	mplayer:multimedia/mplayer \
		mpg123:audio/mpg123 \
		ogg123:audio/vorbis-tools \
		p5-GDBM>=0:databases/p5-GDBM \
		spline:graphics/plotutils

USES=		perl5 shebangfix
SHEBANG_FILES=	${SCRS}
CFLAGS+=	-I${LOCALBASE}/include -L. -L${LOCALBASE}/lib
MAKE_ENV=	VPATH=common
PORTDOCS=	README
BINS=		sonic_reducer vector_pairs
SCRS=		${PORTNAME} ${PORTNAME}_bench cleanup_dups optparam
PLIST_FILES=	${BINS:S,^,bin/,} ${SCRS:S,^,bin/,}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -Ee '/^(CFLAGS|CC) =/s|.*||' -e 's|common/||g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

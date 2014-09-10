# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdmf
DISTVERSION=	0.0.9s
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://w140.com/audio/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find similar music by perceptual hashing

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libplot.so:${PORTSDIR}/graphics/plotutils \
		libfftw3.so:${PORTSDIR}/math/fftw3
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		p5-GDBM>=0:${PORTSDIR}/databases/p5-GDBM

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

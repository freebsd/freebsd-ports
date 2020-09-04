# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=	mapm3
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.broad.mit.edu/ftp/distribution/software/mapmaker3/ \
		ftp://ftp.ibiblio.org/pub/academic/biology/molbio/mapmaker/   \
		http://iubio.bio.indiana.edu/soft/molbio/qtl/mapmaker/        \
		http://www.mirrorservice.org/sites/iubio.bio.indiana.edu/molbio/qtl/mapmaker/
DISTNAME=	mapm3-source

MAINTAINER=	tphilipp@potion-studios.com
COMMENT=	Constructs linkage maps of markers segregating in experimental crosses

LICENSE=	MAPMAKER
LICENSE_NAME=	Whitehead Institute Mapmaker license
LICENSE_FILE=	${WRKSRC}/READ.ME
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		ncurses tar:Z
USE_CSTD=	gnu89

MAKE_ARGS+=	SYS_LIBS="${LDFLAGS} -lm -lncurses"
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-fcommon -Wno-return-type
NO_WRKSUBDIR=	yes

post-patch:
	${CP} ${WRKSRC}/sun/* ${WRKSRC}

pre-install:
	@${REINPLACE_CMD} -e 's|/usr/local|${STAGEDIR}${PREFIX}|' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mapmaker
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qtl

.include <bsd.port.mk>

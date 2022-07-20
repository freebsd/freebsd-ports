PORTNAME=	libowfat
PORTVERSION=	0.32
CATEGORIES=	devel
MASTER_SITES=	https://www.fefe.de/libowfat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose library based on code by D. J. Bernstein

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:xz
MAKEFILE=	GNUmakefile
ALL_TARGET=	dep all

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

.include <bsd.port.pre.mk>

MAKE_ENV+=	INSTALL="${INSTALL}"

.include "${FILESDIR}/manpages"

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O2 -fomit-frame-pointer
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/man
# Manual pages clash with other programs; prepend libowfat_ to them.
.for i in ${MANPAGES}
	@${MV} ${WRKSRC}/*/${i:S/libowfat_//} ${WRKSRC}/man/${i}
.endfor

post-patch:
# Clang cries when void functions return a value
	${REINPLACE_CMD} -e '56s|return ||' ${WRKSRC}/CAS.h
	${REINPLACE_CMD} -e "s|STAGEDIR|${STAGEDIR}|g" ${WRKSRC}/GNUmakefile

.include <bsd.port.post.mk>

# Created by: db
# $FreeBSD$

PORTNAME=	libfec
PORTVERSION=	3.0.1
CATEGORIES=	comms astro hamradio math
MASTER_SITES=	http://www.ka9q.net/code/fec/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	fec-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Several forward error correction (FEC) decoders

MAKEFILE=	makefile

GNU_CONFIGURE=	yes
USES=		gmake
USE_BZIP2=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST_FILES=	include/fec.h		\
		lib/libfec.so		\
		lib/libfec.a		\
		man/man3/dsp.3.gz	\
		man/man3/rs.3.gz	\
		man/man3/simd-viterbi.3.gz

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_DATA} ${WRKSRC}/fec.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libfec.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libfec.so ${STAGEDIR}${PREFIX}/lib
.for _man in dsp.3 simd-viterbi.3 rs.3
	${INSTALL_MAN} ${WRKSRC}/${_man} ${STAGEDIR}${MAN3PREFIX}/man/man3
.endfor

.include <bsd.port.post.mk>

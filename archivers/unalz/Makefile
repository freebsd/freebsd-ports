PORTNAME=	unalz
DISTVERSION=	0.66
CATEGORIES=	archivers
MASTER_SITES=	https://BSDforge.com/projects/source/archivers/unalz/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Extracts AlZip archives
WWW=		https://bsdforge.com/projects/archivers/unalz/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/readme.txt

BROKEN=		Unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		cpe iconv localbase:ldflags tar:xz
MAKE_ARGS+=	CPP="${CXX}" CC="${CC}" OBJ="${UNALZ_OBJS}" \
		LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}"
ALL_TARGET=	posix-utf8

LDFLAGS+=	-lz -lbz2

PLIST_FILES=	bin/${PORTNAME}

UNALZ_OBJS=	main.o UnAlz.o UnAlzUtils.o UnAlzBz2decompress.o \
		UnAlzBzip2.o UnAlzbzlib.o

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=  -Dregister=
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's/-liconv/${ICONV_LIB}/g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e \
		'/<sys\/timeb.h>/d' ${WRKSRC}/main.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

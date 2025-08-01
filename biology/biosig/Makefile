PORTNAME=	biosig
DISTVERSION=	2.6.1
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/BioSig%20for%20C_C%2B%2B/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for reading and writing different biosignal data format
WWW=		https://biosig.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libb64.so:converters/libb64 \
		libcholmod.so:math/suitesparse-cholmod \
		libiconv.so:converters/libiconv \
		libtinyxml.so:textproc/tinyxml

USES=		gmake iconv localbase:ldflags tar:xz
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CFLAGS+=	-D__BYTE_ORDER=BYTE_ORDER -D__LITTLE_ENDIAN=LITTLE_ENDIAN -D__BIG_ENDIAN=BIG_ENDIAN \
		-Dbswap_16=bswap16 -Dbswap_32=bswap32 -Dbswap_64=bswap64
LDFLAGS+=	-liconv

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
.for f in bin/biosig_fhir bin/biosig2gdf bin/physicalunits bin/save2gdf lib/libbiosig.so.3
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.endfor

.include <bsd.port.post.mk>

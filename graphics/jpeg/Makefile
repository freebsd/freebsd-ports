# Created by: smace
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	8
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://www.ijg.org/files/ \
		http://sylvana.net/jpegcrop/:exif
DISTNAME=	jpegsrc.v${DISTVERSION2}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		jpegexiforient.c:exif exifautotran.txt:exif
DIST_SUBDIR=	${PORTNAME}${DISTVERSION2}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	IJG's jpeg compression utilities

CONFLICTS_INSTALL=	jpeg-turbo-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION2}
DISTVERSION2=	8d
USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ADDITIONAL_HEADER=	jinclude.h jpegint.h

# define J_MAXMEM like "make J_MAXMEM=32" to limit max processing memory to 32Mb
.if defined(J_MAXMEM)
CONFIGURE_ARGS+=	--enable-maxmem=${J_MAXMEM}
.endif

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/jpegexiforient.c ${WRKSRC}/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/exifautotran.txt ${WRKSRC}/exifautotran

post-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o jpegexiforient jpegexiforient.c

test: build
	${SETENV} LD_LIBRARY_PATH=${WRKSRC}/.libs ${MAKE} -C ${WRKSRC} test

regression-test:	test

post-install:
.for header in ${ADDITIONAL_HEADER}
	${INSTALL_DATA} ${WRKSRC}/${header} ${STAGEDIR}${PREFIX}/include/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/jpegexiforient ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/exifautotran ${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/jpeg/
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${PREFIX}/share/doc/jpeg/

.include <bsd.port.mk>

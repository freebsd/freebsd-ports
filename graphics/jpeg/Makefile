# Created by: smace
# $FreeBSD$

PORTNAME=	jpeg
PORTVERSION=	8
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.ijg.org/files/ \
		http://sylvana.net/jpegcrop/:exif
DISTNAME=	jpegsrc.v${DISTVERSION2}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		jpegexiforient.c:exif exifautotran.txt:exif
DIST_SUBDIR=	${PORTNAME}${DISTVERSION2}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	IJG's jpeg compression utilities

CONFLICTS=	libjpeg-turbo-[0-9]*
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION2}

DISTVERSION2=	8d
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static

ADDITIONAL_HEADER=	jinclude.h jpegint.h

# define J_MAXMEM like "make J_MAXMEM=32" to limit max processing memory to 32Mb
.if defined(J_MAXMEM)
CONFIGURE_ARGS+=	--enable-maxmem=${J_MAXMEM}
.endif

MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

.include <bsd.port.options.mk>

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/jpegexiforient.c ${WRKSRC}/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/exifautotran.txt ${WRKSRC}/exifautotran

post-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o jpegexiforient jpegexiforient.c

test: build
	${SETENV} LD_LIBRARY_PATH=${WRKSRC}/.libs ${MAKE} -C ${WRKSRC} test

regression-test:	test

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/jpeg
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jpeg/
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/jpeg/
.endif
.for header in ${ADDITIONAL_HEADER}
	@${INSTALL_DATA} ${WRKSRC}/${header} ${PREFIX}/include/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/jpegexiforient ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/exifautotran ${PREFIX}/bin/

.include <bsd.port.mk>

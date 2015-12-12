# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	praat
PORTVERSION=	5.4.08
PORTREVISION=	1
CATEGORIES=	audio science
MASTER_SITES=	http://www.fon.hum.uva.nl/praat/
DISTNAME=	praat5408_sources

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Phonetics by Computer

BROKEN=		unfetchable

LICENSE=	GPLv2

DOS2UNIX_REGEX=	.*Makefile
USES=		dos2unix iconv pkgconfig
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/sources_5408
MAKEFILE=	makefile
PLIST_FILES=	bin/praat man/man1/praat.1.gz

LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
# Requires std=g++11
USE_GCC=	yes
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|' "{}" \;
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' "{}" \;
	@${CP} ${FILESDIR}/makefile.defs.freebsd.alsa \
		${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|g' \
			  -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/makefile.defs
	@${REINPLACE_CMD} -e 's| log2| NUMlog2|g' \
			  -e 's|feof (f)|feof (f.get_ptr())|g' \
			  -e 's|ferror (f)|ferror (f.get_ptr())|g' \
		${WRKSRC}/dwtools/Sound_extensions.cpp \
		${WRKSRC}/fon/Sound_files.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>

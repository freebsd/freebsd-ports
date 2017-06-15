# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	praat
PORTVERSION=	5.4.08
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	audio science

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Phonetics by Computer

LICENSE=	GPLv2

USE_GITHUB=	yes
DOS2UNIX_REGEX=	.*Makefile
USES=		dos2unix iconv pkgconfig
USE_GNOME=	gtk20
MAKEFILE=	makefile
PLIST_FILES=	bin/praat man/man1/praat.1.gz

post-patch:
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|' {} \;
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CPPFLAGS =|CPPFLAGS +=|' {} \;
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

.include <bsd.port.mk>

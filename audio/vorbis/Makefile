# New ports collection makefile for:	vorbis
# Date created:				22 August 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis
PORTVERSION=	20000821
CATEGORIES=	audio
MASTER_SITES=	http://home.student.utwente.nl/t.vanklaveren/distfiles/

MAINTAINER=	t.vanklaveren@student.utwente.nl

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		xmms.1:${PORTSDIR}/audio/xmms

WRKSRC=		${WRKDIR}/${PORTNAME}

# Vorbis doesn't depend on X, but it's needed for the XMMS plugin :-(
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_AUTOCONF=	yes

MAN1=	ogg123.1 vorbize.1 oggenc.1

post-build:
	cd ${WRKSRC}/vorbis-tools/libao && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/vorbis-tools && ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}
	cd ${WRKSRC}/xmms && ${SETENV} ${MAKE_ENV} ${MAKE} target

do-install:
# Install all vorbis libraries and headers by hand. There is no target for it.
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libvorbis.a ${PREFIX}/lib/
	${INSTALL_PROGRAM} ${WRKSRC}/lib/vorbisfile.a ${PREFIX}/lib/
# Install all vorbis-tools by hand. The Makefile sucks and is beyond hope.
	${INSTALL_PROGRAM} ${WRKSRC}/vorbis-tools/vorbize ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/vorbis-tools/mp3tovorbis ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/vorbis-tools/ogg123 ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/vorbis-tools/vorbiscomment ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/vorbis-tools/oggenc ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/vorbis-tools/ogg123.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/vorbis-tools/vorbize.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/vorbis-tools/oggenc.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/xmms/libvorbis.so ${PREFIX}/lib/xmms/Input/
# And finally, the header files
	${MKDIR} ${PREFIX}/include/vorbis
	${MKDIR} ${PREFIX}/include/vorbis/book
	${INSTALL_DATA} ${WRKSRC}/include/vorbis/*.h ${PREFIX}/include/vorbis/
	${INSTALL_DATA} ${WRKSRC}/include/vorbis/book/*.vqh ${PREFIX}/include/vorbis/book/

.include <bsd.port.mk>

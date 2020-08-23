# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	squash
PORTVERSION=	1.0
PORTREVISION=	18
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Learning console-based MP3/OGG player

LICENSE=	GPLv2+

LIB_DEPENDS+=	libao.so:audio/libao \
		libfftw.so:math/fftw \
		libFLAC.so:audio/flac \
		libid3.so:audio/id3lib \
		libmad.so:audio/libmad \
		libvorbis.so:audio/libvorbis
RUN_DEPENDS=	id3v2:audio/id3v2

USES=		compiler:c11 gmake ncurses tar:bzip2
USE_RUBY=	yes
MAKE_ARGS=	CC="${CC}"
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e "s|--std=gnu99|--std=gnu99 ${CFLAGS}|; \
		s|-Iinclude|-Iinclude -I${LOCALBASE}/include|; \
		s|-ldl|-L${LOCALBASE}/lib|; \
		s}^LDFLAGS.*:=\(.*\)}LDFLAGS :=\1 ${LDFLAGS}}" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,/usr/bin/ruby,${RUBY}," \
		${WRKSRC}/extra/*.rb
	@${REINPLACE_CMD} -e "s,/etc/squash.conf,${PREFIX}/etc/squash.conf," \
		${WRKSRC}/src/global.c

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/squash ${STAGEDIR}${PREFIX}/bin
.for FILE in collect_info edit_tag export_music import_music joystick uncollect_info
	${INSTALL_SCRIPT} ${WRKSRC}/extra/${FILE}.rb ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/musicdb_lib.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/squash.conf ${STAGEDIR}${PREFIX}/etc/squash.conf.dist
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README doc/FEATURES doc/LOCKS doc/INSTALL doc/USERS_GUIDE
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

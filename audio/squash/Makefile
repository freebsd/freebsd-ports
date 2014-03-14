# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=		squash
PORTVERSION=		1.0
PORTREVISION=	11
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Learning console-based MP3/OGG player

LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac \
		libfftw.so:${PORTSDIR}/math/fftw \
		libid3.so:${PORTSDIR}/audio/id3lib \
		libmad.so:${PORTSDIR}/audio/mad \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libao.so:${PORTSDIR}/audio/libao
RUN_DEPENDS=	id3v2:${PORTSDIR}/audio/id3v2

USE_BZIP2=	yes
USES=		gmake
USE_RUBY=	yes
MAKE_ARGS=	CC=${CC}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|--std=gnu99|--std=gnu99 ${CFLAGS} ${PTHREAD_CFLAGS}|; \
		s|-Iinclude|-Iinclude -I${LOCALBASE}/include|; \
		s|-lpthread|${PTHREAD_LIBS}|; s|-ldl|-L${LOCALBASE}/lib|" ${WRKSRC}/Makefile
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README doc/FEATURES doc/LOCKS doc/INSTALL doc/USERS_GUIDE
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

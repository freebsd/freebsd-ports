# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=		squash
PORTVERSION=		1.0
PORTREVISION=	9
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Learning console-based MP3/OGG player

LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac \
		fftw:${PORTSDIR}/math/fftw \
		id3:${PORTSDIR}/audio/id3lib \
		mad:${PORTSDIR}/audio/mad \
		vorbis:${PORTSDIR}/audio/libvorbis \
		ao:${PORTSDIR}/audio/libao
RUN_DEPENDS=	id3v2:${PORTSDIR}/audio/id3v2

NO_STAGE=	yes
USE_BZIP2=	yes
USES=		gmake
USE_RUBY=	yes
MAKE_ARGS=	CC=${CC}

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
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/squash ${PREFIX}/bin
.for FILE in collect_info edit_tag export_music import_music joystick uncollect_info
	${INSTALL_SCRIPT} ${WRKSRC}/extra/${FILE}.rb ${PREFIX}/bin
.endfor
	${MKDIR} ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/musicdb_lib.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/squash.conf ${PREFIX}/etc/squash.conf.dist
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in README doc/FEATURES doc/LOCKS doc/INSTALL doc/USERS_GUIDE
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

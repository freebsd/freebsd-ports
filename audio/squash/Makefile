# New ports collection makefile for: squash
# Date created:		5 August 2003
# Whom:			Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$

PORTNAME=		squash
PORTVERSION=		1.0.p1
PORTREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SAVANNAH} \
       			${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTNAME} \
			pav/:local
DISTNAME=		squash-1.0pre1
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}:DEFAULT,local

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Learning console-based MP3/OGG player

LIB_DEPENDS+=	FLAC.5:${PORTSDIR}/audio/flac \
		fftw.2:${PORTSDIR}/math/fftw \
		id3-3.8.3:${PORTSDIR}/audio/id3lib \
		mad.2:${PORTSDIR}/audio/mad \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		ao.3:${PORTSDIR}/audio/libao
RUN_DEPENDS=	id3v2:${PORTSDIR}/audio/id3v2

PKGMESSAGE=	${WRKDIR}/pkg-message
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|--std=gnu99|${CFLAGS} ${PTHREAD_CFLAGS}|; \
		s|-Iinclude|-Iinclude -I${LOCALBASE}/include|; \
		s|-lpthread|${PTHREAD_LIBS}|; s|-ldl|-L${LOCALBASE}/lib|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,/usr/bin/ruby,${RUBY}," \
		${WRKSRC}/extra/*.rb
	@${REINPLACE_CMD} -e "s,/etc/squash.conf,${PREFIX}/etc/squash.conf," \
		${WRKSRC}/src/global.c
	@${SED} "s,%%DD%%,${DOCSDIR}," ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/squash ${PREFIX}/bin
.for FILE in collect_info edit_tag export_music import_music joystick uncollect_info
	${INSTALL_SCRIPT} ${WRKSRC}/extra/${FILE}.rb ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/extra/musicdb_lib.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/squash.conf ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README doc/FEATURES doc/LOCKS doc/INSTALL doc/USERS_GUIDE
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 501100

IGNORE=	"ignored: FreeBSD before 5.1 lacks the wordexp interface"

.endif

.include <bsd.port.post.mk>

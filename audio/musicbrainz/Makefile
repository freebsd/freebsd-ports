# New ports collection makefile for:	musicbrainz
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	roman@xpert.com

USE_AUTOCONF=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

pre-extract:
.if !defined(WITHOUT_VORBIS)
	@${ECHO}
	@${ECHO} "You can disable Vorbis support by defining WITHOUT_VORBIS"
	@${ECHO}
LIB_DEPENDS+=	vorbis.0:${PORTSDIR}/audio/libvorbis
HAVE_VORBIS=	yes
.endif

post-extract:
	@${RM} ${WRKSRC}/config.sub ${WRKSRC}/config.guess ;\
	${LN} -s ${AUTOCONF_DIR}/config.* ${WRKSRC}/ ;\
	${PERL} -pi -e 's/-ldl//g' ${WRKSRC}/examples/Makefile.*

.include <bsd.port.mk>

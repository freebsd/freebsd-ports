# New ports collection makefile for:	audacity
# Date created:				21 Jul 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	arved@FreeBSD.org

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	wx_gtk-2.2.2:${PORTSDIR}/x11-toolkits/wxgtk \
		mad.1:${PORTSDIR}/audio/mad

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
AUDACITY_HELP_DIR=	${PREFIX}/share/doc/audacity
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		CFLAGS="-DAUDACITY_HELP_DIR=${AUDACITY_HELP_DIR} ${PTHREAD_CFLAGS}"
CONFIGURE_ARGS+=	--with-id3=no --with-libmad=yes

.include <bsd.port.pre.mk>

.if defined(WITH_ARTS)
LIB_DEPENDS+=	qtmcop.1:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--with-arts-soundserver=yes
.endif

.if !defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis
.endif

pre-everything:
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS.MSG."
.endif
.if !defined(WITH_ARTS)
	@${ECHO_MSG} "You can use artsd instead of OSS for output by defining WITH_ARTS."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/audacity ${PREFIX}/bin/audacity
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/audacity
	${INSTALL_DATA} ${WRKSRC}/audacity-help.htb ${WRKSRC}/README.txt ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/audacity/
.endif

.include <bsd.port.post.mk>

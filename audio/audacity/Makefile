# New ports collection makefile for:	audacity
# Date created:				21 Jul 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	0.98
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	freebsdports@arved.de

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk \
		mad.1:${PORTSDIR}/audio/mad

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
AUDACITY_HELP_DIR=	${PREFIX}/share/doc/audacity
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-DAUDACITY_HELP_DIR=${AUDACITY_HELP_DIR}"
CONFIGURE_ARGS+=	--with-id3=no --with-libmad=yes

.if defined(WITH_ARTS)
LIB_DEPENDS+=	qtmcop.1:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--with-arts-soundserver=yes
.endif

.if !defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis

pre-everything:
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS.MSG."
.endif
.if !defined(WITH_ARTS)
	@${ECHO_MSG} "You can use artsd instead of OSS for output by defining WITH_ARTS."
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/audacity ${PREFIX}/bin/audacity
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/audacity
	${INSTALL_DATA} ${WRKSRC}/audacity-help.htb ${PREFIX}/share/doc/audacity/audacity-help.htb
.endif

.include <bsd.port.mk>

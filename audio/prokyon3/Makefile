# New ports collection makefile for:           prokyon3
# Date created:                                11 November 2002
# Whom:                                        Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	prokyon3
PORTVERSION=	0.9.6
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multithreaded music manager and tag editor

BUILD_DEPENDS=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		mad.2:${PORTSDIR}/audio/libmad \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		tag.1:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin

USE_XORG=	x11 xft
USE_QT_VER=	3
USE_GNOME=	gnometarget
USE_MYSQL=	yes
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-other-includes=${LOCALBASE}/include \
		--with-other-libs=${LOCALBASE}/lib \
		--without-mixxx --without-musicextras
MAKE_ARGS=	LIBS="-lqt-mt ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if defined(WITH_BURN)
USE_CDRTOOLS=	yes
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		normalize:${PORTSDIR}/audio/normalize \
		bash:${PORTSDIR}/shells/bash
PLIST_FILES+=	BURN=""
.else
PLIST_SUB+=	BURN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!.*$$|#!${LOCALBASE}/bin/bash|g ; \
		 s|^CXXFLAGS=|#CXXFLAGS=|g ; \
		 s|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^#!.*$$|#!${LOCALBASE}/bin/bash|g' ${WRKSRC}/prokburn
	@${REINPLACE_CMD} -e \
		's|: install-binSCRIPTS|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|getopt.$$(OBJEXT)||g' ${WRKSRC}/src/Makefile.in

post-install:
.if defined(WITH_BURN)
	${INSTALL_SCRIPT} ${WRKSRC}/prokburn ${PREFIX}/bin
.endif
	@${CAT} ${PKGMESSAGE}
	@sleep 5

.include <bsd.port.post.mk>

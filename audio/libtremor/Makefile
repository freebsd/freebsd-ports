# New ports collection makefile for:	libtremor
# Date created:				07 December 2003
# Whom:					kwm@rainbow-runner.nl
#
# $FreeBSD$
#

PORTNAME=	libtremor
PORTVERSION=	1.0.2.${SNAP_DATE}
CATEGORIES=	audio
MASTER_SITES=	http://members.chello.nl/~g.mast/distfiles/
DISTNAME=	tremor_snapshot_${SNAP_DATE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Integer-only fully Ogg Vorbis compliant decoder library

SNAP_DATE=	02132004
WRKSRC=		${WRKDIR}/Tremor
USE_REINPLACE=	yes
USE_AUTOMAKE_VER=	15
USE_AUTOCONF_VER=	253
USE_LIBTOOL_VER=	13
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}
	@cd ${WRKSRC} && ${LIBTOOLIZE} --automake
	@cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	@cd ${WRKSRC} && ${AUTOCONF}

do-install:
	for i in ${WRKSRC}/.libs/libvorbisidec.so.1		\
			${WRKSRC}/.libs/libvorbisidec.so	\
			${WRKSRC}/.libs/libvorbisidec.a ; do	\
		${INSTALL_SCRIPT} $$i ${PREFIX}/lib ;		\
	done
	@${MKDIR} ${PREFIX}/include/tremor
	for i in ${WRKSRC}/config_types.h			\
			${WRKSRC}/ivorbiscodec.h		\
			${WRKSRC}/ivorbisfile.h			\
			${WRKSRC}/ogg.h				\
			${WRKSRC}/os_types.h ; do		\
		${INSTALL_SCRIPT} $$i ${PREFIX}/include/tremor ; \
	done

.include <bsd.port.mk>

# New ports collection makefile for:	replay
# Version required:		0.61
# Date created:			Oct 27 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	replay-source-dgtk_0.61
PKGNAME=	replay-0.61
CATEGORIES=	audio
MASTER_SITES=	http://replay.replicant.nu/files/ \
		ftp://ftp.icemark.ch/pub/replay/ \
		ftp://k2.lund.se/pub/replay/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		esd.2:${PORTSDIR}/audio/esound

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(USE_I18N)
CONFIGURE_ARGS+=       --enable-i18n=JAPANESE
.endif

pre-configure:
.if !defined(USE_I18N)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you would like build replay with I18N support"
	@${ECHO_MSG} "you must set the variable USE_I18N"
	@${ECHO_MSG} "(Now JAPANESE only)"
	@${ECHO_MSG}
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "Building replay with I18N support"
	@${ECHO_MSG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/replay ${PREFIX}/bin

.include <bsd.port.mk>

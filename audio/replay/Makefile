# New ports collection makefile for:	replay
# Date created:			Oct 27 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	replay
PORTVERSION=	0.61
CATEGORIES=	audio
MASTER_SITES=	http://replay.replicant.nu/files/ \
		ftp://ftp.icemark.ch/pub/replay/ \
		ftp://k2.lund.se/pub/replay/
DISTNAME=	${PORTNAME}-source-dgtk_${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_ESOUND=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_I18N)
CONFIGURE_ARGS+=	--enable-i18n=JAPANESE
.endif

pre-configure:
.if !defined(WITH_I18N)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you would like build replay with I18N support"
	@${ECHO_MSG} "you must set the variable WITH_I18N"
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

# New ports collection makefile for:	replay
# Date created:			Oct 27 1998
# Whom:				Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	replay
PORTVERSION=	0.61
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/gtkbuffet/apps/replay
DISTNAME=	${PORTNAME}-source-dgtk_${PORTVERSION}

DEPRECATED=	"no longer on sunsite, home page gone"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another GTK-based mp3 player

PLIST_FILES=	bin/replay
USE_X_PREFIX=	yes
USE_GNOME=	gtk12 esound
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_I18N)
CONFIGURE_ARGS+=	--enable-i18n=JAPANESE
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
BROKEN=		"Does not compile on alpha 5.x"
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

.include <bsd.port.post.mk>

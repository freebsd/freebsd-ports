# New ports collection makefile for:	TEA
# Date created:				13 Jul 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	tea
DISTVERSION=	17.0.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tea-editor

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A simple and powerful GTK+ text editor

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	TEA_ONLY	"Build original GTK-only version"	on \
		ASPELL		"Build with GNU aspell support"		on

.include <bsd.port.pre.mk>

.if defined(WITH_TEA_ONLY)
CONFIGURE_ARGS+=	--enable-legacy
.else
USE_GNOME+=	gtksourceview
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|/tea/doc/|/doc/tea/|' \
		${WRKSRC}/src/tea_defs.h
# Fix FINK-related defines
	${REINPLACE_CMD} -e '5702d; 5705,5708d' ${WRKSRC}/configure
# Do not install yet another copy of GPL
	${REINPLACE_CMD} -e '634d' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

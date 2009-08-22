# New ports collection makefile for:	TEA
# Date created:				13 Jul 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	tea
DISTVERSION=	17.6.0
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}-editor/${PORTNAME}-editor/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A simple and powerful GTK+ text editor

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	TEA_ONLY	"Build original GTK-only version"	on \
		ASPELL		"Build with GNU aspell support"		on \
		CURL		"Build with libCURL support"		off

.include <bsd.port.pre.mk>

.if defined(WITH_TEA_ONLY)
CONFIGURE_ARGS+=	--enable-legacy
.else
USE_GNOME+=	gtksourceview
.endif

.if defined(WITH_ASPELL) || exists(${LOCALBASE}/lib/libaspell.so)
LIB_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.endif

.if defined(WITH_CURL) || exists(${LOCALBASE}/lib/libcurl.so)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

post-patch: .SILENT
# Correct documentation location in FreeBSD world
	${REINPLACE_CMD} -e 's|/tea/doc/|/doc/tea/|' \
		${WRKSRC}/src/tea_defs.h
# Fix FINK-related defines (pretend we're Darwin)
	${REINPLACE_CMD} -e '5711d; 5714,5717d' ${WRKSRC}/configure
# Do not install yet another copy of GPL
	${REINPLACE_CMD} -e '641d' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

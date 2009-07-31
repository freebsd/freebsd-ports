# New ports collection makefile for:	logjam
# Date created:		13 Aug 01
# Whom:			alanp@unixpower.org
#
# $FreeBSD$
#

PORTNAME=	logjam
PORTVERSION=	4.5.3
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	http://logjam.danga.com/download/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A GTK2 interface to livejournals, ie www.livejournal.com

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl

MAN1=		logjam.1

USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 libxml2 intlhack
CONFIGURE_ARGS=	--program-transform-name="s/$$//"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.ifndef(WITHOUT_GTKSPELL)
LIB_DEPENDS+=		gtkspell.0:${PORTSDIR}/textproc/gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=	--with-sqlite3
LIB_DEPENDS+=		sqlite3.8:${PORTSDIR}/databases/sqlite3
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=		xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=		WITH_XMMS=""
.else
PLIST_SUB+=		WITH_XMMS="@comment "
CONFIGURE_ARGS+=	--without-xmms
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtkhtml3}!=""
USE_GNOME+=		gtkhtml3
.else
CONFIGURE_ARGS+=	--without-gtkhtml
.endif

.if ${HAVE_GNOME:Mlibrsvg2}!=""
USE_GNOME+=		librsvg2
.else
CONFIGURE_ARGS+=	--without-librsvg
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "logjam has the following tunable option(s):"
	@${ECHO_MSG} "		WITHOUT_GTKSPELL	Disable spell checking"
	@${ECHO_MSG} "		WITH_XMMS		Enable XMMS music detection"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|libgtkhtml-3.0|libgtkhtml-3.18|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>

# New ports collection makefile for:	BitchX ircII client
# Date created:		26 Jan 1998
# Whom:			griffin
#
# $FreeBSD$
#

PORTNAME=	BitchX
PORTVERSION=	1.0c17
CATEGORIES=	irc gnome
MASTER_SITES=	ftp://ftp.bitchx.com/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/

MAINTAINER=	cj@vallcom.net

WRKSRC=		${WRKDIR}/BitchX

USE_AUTOCONF=	yes
USE_GMAKE=	yes
WANT_ESOUND=	yes
WANT_GNOME=	yes
CONFIGURE_ARGS=	--exec-prefix="${PREFIX}/share" \
		--bindir="${PREFIX}/bin" \
		--datadir="${PREFIX}/share" \
		--libdir="${PREFIX}/share"
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L{LOCALBASE}/lib"

MAN1=		BitchX.1

.include <bsd.port.pre.mk>

.if defined(HAVE_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=--with-gtk
.else
CONFIGURE_ARGS+=--without-gtk
.endif
.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
CONFIGURE_ARGS+=--enable-sound
.endif

.if defined(WITH_TCL)
BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.3/tcl.h:${PORTSDIR}/lang/tcl83
CONFIGURE_ARGS+=--with-tcl \
		--with-tcl-includes=/usr/local/include/tcl8.3 \
		--with-tcl-libs=/usr/local/lib
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl8.3"
post-extract:
	@uudecode -p ${FILESDIR}/tcl-freebsd.o.uu > ${WRKSRC}/source/tcl.o
.endif

.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=--with-plugins=pkga,possum,encrypt,hint,abot,acro,amp,blowfish,scan,wavplay,qmail,fserv,nap,qbx
PLIST_SUB+=	PLUGINS:=""
.else
CONFIGURE_ARGS+=--without-plugins
PLIST_SUB+=	PLUGINS:="@comment "
.endif

.if defined(WITH_LATIN)
pre-patch:
	@${PERL} -pi -e "s!#undef LATIN1!#define LATIN1!" ${WRKSRC}/include/config.h
.endif

pre-extract:
	@${ECHO} "Available switches:"
	@${ECHO} "-------------------"
	@${ECHO} "WITH_PLUGINS - Build the plugins"
	@${ECHO} "WITH_LATIN - Recommended if you are using an ISO-8859-1 display"
	@${ECHO} "WITH_TCL - Build BitchX with TCL scripting"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/bx/help
	${MKDIR} ${PREFIX}/share/doc/bitchx
	${TAR} --directory ${WRKSRC}/bitchx-docs -cf - . --exclude CVS | \
	${TAR} --directory ${PREFIX}/share/bx/help -xf -
	${INSTALL_DATA} ${WRKSRC}/doc/bxfaq.html ${PREFIX}/share/doc/bitchx
.endif

.include <bsd.port.post.mk>

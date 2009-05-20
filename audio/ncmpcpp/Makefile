# New ports collection makefile for:	ncmpcpp
# Date created:		August 25 2008
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	ncmpcpp
PORTVERSION=	0.3.4
CATEGORIES=	audio
MASTER_SITES=	http://unkart.ovh.org/ncmpcpp/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A ncurses mpd client, clone of ncmpc with some new features

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_GNOME=	glib20
USE_AUTOTOOLS=	automake:110 aclocal:110 libtool:15
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lpthread"

MAN1=	ncmpcpp.1
MAKE_JOBS_SAFE=	yes

OPTIONS=	CURL "Enable fetching lyrics from the Internet" on \
		CLOCK "Enable clock-screen support" on \
		UTF8 "Enable UTF8 support" on \
		TAGLIB "Enable taglib support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
LIB_DEPENDS+=	ncursesw.5:${PORTSDIR}/devel/ncurses
.else
# no need to use ncurses-config if we use ncurses from the base system
CONFIGURE_ARGS+=	NCURSES_CONFIG=/usr/bin/true
.endif

PLIST_FILES=	bin/ncmpcpp \
		%%DOCSDIR%%/config \
		%%DOCSDIR%%/keys \
		%%DOCSDIR%%/NEWS \
		%%DOCSDIR%%/AUTHORS \
		%%DOCSDIR%%/COPYING
PLIST_DIRS=	%%DOCSDIR%%

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl
.else
CONFIGURE_ARGS+=	--with-curl=no
.endif

.if !defined(WITHOUT_CLOCK)
CONFIGURE_ARGS+=	--enable-clock
.else
CONFIGURE_ARGS+=	--disable-clock
.endif

.if !defined(WITHOUT_UTF8)
CONFIGURE_ARGS+=	--enable-unicode
.else
CONFIGURE_ARGS+=	--disable-unicode
.endif

.if !defined(WITHOUT_TAGLIB)
LIB_DEPENDS+=	tag:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib
.else
CONFIGURE_ARGS+=	--with-taglib=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/i18n/SUPPORTED|${LOCALBASE}/share/locale|g' \
		-e 's|iconv.h|sys/iconv.h|g' ${WRKSRC}/configure*

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ncmpcpp ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}/NEWS
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/AUTHORS
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/config ${DOCSDIR}/config
	${INSTALL_DATA} ${WRKSRC}/doc/keys ${DOCSDIR}/keys
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>

PORTNAME=	gnuitar
PORTVERSION=	0.3.2
PORTREVISION=	11
CATEGORIES=	audio multimedia
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Real-time guitar processor
WWW=		https://sourceforge.net/projects/gnuitar/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained, last upstream release in 2005
EXPIRATION_DATE=2024-04-17

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		gmake gnome pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-clip-everywhere \
		--enable-float \
		--with-gtk2

DESKTOP_ENTRIES=	"GNUitar" \
			"Apply guitar effects in real-time" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
			"gnuitar" \
			"" \
			true

TXT_DOCS=	AUTHORS COPYING FAQ INSTALL NEWS README TODO ChangeLog
HTML_DOCS=	faq.html index.html install.html readme.html
PORTDOCS=	${HTML_DOCS} ${TXT_DOCS}

OPTIONS_DEFINE=		DOCS SUID
OPTIONS_DEFAULT=	SUID
OPTIONS_SUB=		yes

SUID_DESC=	Use suid to allow highest priority (priv. dropped)

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnuitar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/gnuitar.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${TXT_DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${HTML_DOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

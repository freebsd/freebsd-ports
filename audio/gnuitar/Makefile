# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	gnuitar
PORTVERSION=	0.3.2
PORTREVISION=	9
CATEGORIES=	audio multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time guitar processor

USE_GNOME=	gtk20
USES=		gmake gnome pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2 \
		--enable-clip-everywhere \
		--enable-float

TXT_DOCS=	AUTHORS COPYING FAQ INSTALL NEWS README TODO ChangeLog
HTML_DOCS=	faq.html index.html install.html readme.html
PORTDOCS=	${TXT_DOCS} ${HTML_DOCS}

DESKTOP_ENTRIES="GNUitar" \
		"Apply guitar effects in real-time" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"gnuitar" \
		"" \
		true

OPTIONS_DEFINE=	SUID DOCS
OPTIONS_DEFAULT=	SUID
SUID_DESC=	Use suid to allow highest priority (priv. dropped)
OPTIONS_SUB=	yes

pre-everything::
	@${CAT} ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnuitar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/gnuitar.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${TXT_DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${HTML_DOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

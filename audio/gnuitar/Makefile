# Created by: Gabor Kovesdan
# $FreeBSD$

PORTNAME=	gnuitar
PORTVERSION=	0.3.2
PORTREVISION=	8
CATEGORIES=	audio multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The real-time guitar processor

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2 \
		--enable-clip-everywhere \
		--enable-float

TXT_DOCS=	AUTHORS COPYING FAQ INSTALL NEWS README TODO ChangeLog
HTML_DOCS=	faq.html index.html install.html readme.html
PORTDOCS=	${TXT_DOCS} ${HTML_DOCS}
USES=		gmake pkgconfig

OPTIONS_DEFINE=	SUID DOCS
OPTIONS_DEFAULT=	SUID
SUID_DESC=	Use suid to allow highest priority (priv. dropped)
OPTIONS_SUB=	yes

DESKTOP_ENTRIES="GNUitar" \
		"Apply guitar effects in real-time" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"gnuitar" \
		"" \
		true

pre-fetch:
	@${CAT} pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnuitar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/gnuitar.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${TXT_DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${HTML_DOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Ports collection Makefile for:	gnuitar
# Date created:				3 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=		gnuitar
PORTVERSION=		0.3.2
PORTREVISION=	6
CATEGORIES=		audio multimedia
MASTER_SITES=		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The real-time guitar processor

USE_BZIP2=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk2 \
		--enable-clip-everywhere \
		--enable-float

TXT_DOCS=	AUTHORS COPYING FAQ INSTALL NEWS README TODO ChangeLog
HTML_DOCS=	faq.html index.html install.html readme.html
PORTDOCS=	${TXT_DOCS} ${HTML_DOCS}

OPTIONS=	SUID	"Use suid to allow highest priority (priv. dropped)"	On

DESKTOP_ENTRIES="GNUitar" \
		"Apply guitar effects in real-time" \
		"gnuitar" \
		"gnuitar" \
		"" \
		true

.include <bsd.port.pre.mk>

pre-fetch:
	@${CAT} pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure ${WRKSRC}/src/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gnuitar ${PREFIX}/bin

post-install:
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/src/gnuitar.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${TXT_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${HTML_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_SUID)
# make it setuid-root to be able to set realtime priority (root
# privileges are dropped in the main routine)
	@${CHMOD} u+s ${PREFIX}/bin/gnuitar
.endif

.include <bsd.port.post.mk>

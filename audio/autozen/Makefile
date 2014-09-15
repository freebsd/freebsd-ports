# Created by: trevor
# $FreeBSD$

PORTNAME=	autozen
PORTVERSION=	2.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.springdaemons.com/soft/ \
		http://www.sourcefiles.org/Miscellaneous/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adjust brain waves with sound

LICENSE=	GPLv2

OPTIONS_DEFINE=	GTK2 DOCS

USES=		shebangfix perl5
SHEBANG_FILES=	zentime
USE_PERL5=	run

DESKTOP_ENTRIES="AutoZen" \
		"BrainWave Generator/Synchronizator" \
		"" \
		"${PORTNAME}" \
		"AudioVideo;Player;GTK;" \
		false

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USES+=		pkgconfig
USE_GNOME=	gtk20
MAKE_ENV+=	GTK_CONFIG="pkg-config gtk+-2.0"
.else
USE_GNOME=	gtk12
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -f autozen seq2wav

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 /^CFLAGS/s| =| ?=| ; \
		 /^PREFIX/s| =| ?=| ; \
		 s|share/AutoZen|${DATADIR_REL}| ; \
		 s|gtk-config|$${GTK_CONFIG}|g ; \
		 s|$$(CC) seq2wav|$$(CC) $$(CFLAGS) seq2wav|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autozen ${WRKSRC}/seq2wav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/zentime ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/autozen.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.seq ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} HTML ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

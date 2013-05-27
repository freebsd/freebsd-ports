# Created by: trevor
# $FreeBSD$

PORTNAME=	autozen
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.springdaemons.com/soft/ \
		http://www.sourcefiles.org/Miscellaneous/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adjust brain waves with sound

LICENSE=	GPLv2

OPTIONS_DEFINE=	GTK2 DOCS

USES=		shebangfix
SHEBANG_FILES=	zentime
USE_PERL5_RUN=	yes

DESKTOP_ENTRIES="AutoZen" \
		"BrainWave Generator/Synchronizator" \
		"" \
		"${PORTNAME}" \
		"AudioVideo;Player;GTK;" \
		false

MAN1=		autozen.1
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
	${INSTALL_PROGRAM} ${WRKSRC}/autozen ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/seq2wav ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/zentime ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/autozen.1 ${MANPREFIX}/man/man1/
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.seq ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${COPYTREE_SHARE} ${WRKSRC}/doc/HTML ${DOCSDIR}
.endif

.include <bsd.port.mk>

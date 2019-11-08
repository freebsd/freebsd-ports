# Created by: trevor
# $FreeBSD$

PORTNAME=	autozen
PORTVERSION=	2.1
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxlabs.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adjust brain waves with sound

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		gnome perl5 pkgconfig shebangfix
SHEBANG_FILES=	zentime
USE_PERL5=	run

DESKTOP_ENTRIES="AutoZen" \
		"BrainWave Generator/Synchronizator" \
		"" \
		"${PORTNAME}" \
		"AudioVideo;Player;GTK;" \
		false

PORTDOCS=	*

USE_GNOME=	gtk20
MAKE_ENV=	GTK_CONFIG="pkg-config gtk+-2.0"

post-extract:
	@cd ${WRKSRC} && ${RM} autozen seq2wav

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 /^CFLAGS/s| =| ?=| ; \
		 /^PREFIX/s| =| ?=| ; \
		 s|share/AutoZen|${DATADIR_REL}| ; \
		 s|gtk-config|$${GTK_CONFIG}|g ; \
		 s|$$(CC) seq2wav|$$(CC) $$(CFLAGS) seq2wav| ; \
		 s|-pthread|-lm|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autozen ${WRKSRC}/seq2wav ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/zentime ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/autozen.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.seq ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} HTML ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

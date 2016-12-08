# Created by: ijliao
# $FreeBSD$

PORTNAME=	pureadmin
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	ftp
MASTER_SITES=	SF/purify/Default/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fam gettext gmake localbase pathfix pkgconfig
USE_GNOME=	intltool libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
LIBS+=		-lX11 -lm

PORTDOCS=	index.txt introduction.txt main_window.txt \
		preferences.txt user_manager.txt

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${REINPLACE_CMD} -e '/install-data-local:/s|install-docs||' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

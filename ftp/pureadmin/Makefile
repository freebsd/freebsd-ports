# Created by: ijliao
# $FreeBSD$

PORTNAME=	pureadmin
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	ftp
MASTER_SITES=	SF/purify/Default/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fam gettext gmake gnome localbase pathfix pkgconfig
USE_GNOME=	intltool libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
LIBS+=		-lX11 -lm

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PORTDOCS=	index.txt introduction.txt main_window.txt \
		preferences.txt user_manager.txt

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${REINPLACE_CMD} -e '/install-data-local:/s|install-docs||' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

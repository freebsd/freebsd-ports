# Created by: ijliao
# $FreeBSD$

PORTNAME=	pureadmin
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	SF/purify/Default/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

LICENSE=	GPLv2

USES=		fam gettext gmake pathfix pkgconfig
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11 -lm

PORTDOCS=	index.txt introduction.txt main_window.txt \
		preferences.txt user_manager.txt

pre-configure:
	@${REINPLACE_CMD} -e '/install-data-local:/s|install-docs||' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

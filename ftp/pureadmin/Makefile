# Created by: ijliao
# $FreeBSD$

PORTNAME=	pureadmin
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	SF/purify/Default/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

USES=		fam gettext gmake pathfix pkgconfig
USE_GNOME=	libglade2
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	index.txt introduction.txt main_window.txt \
		preferences.txt user_manager.txt

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e '/install-data-local:/s|install-docs||' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

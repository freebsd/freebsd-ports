# Created by: Frederic Cambus
# $FreeBSD$

PORTNAME=	babytrans
PORTVERSION=	0.9.1
PORTREVISION=	10
CATEGORIES=	deskutils
MASTER_SITES=	http://fjolliton.free.fr/babytrans/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+/GNOME front-end for Babylon Translator .dic files

USES=        	gmake gettext pathfix
USE_GNOME=	gtk12 gnomeprefix
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

post-patch:
.for file in de es fr pt_BR
	@${REINPLACE_CMD} -e "s|CHARSET|ISO-8859-1|" \
		-e "s|ENCODING|8bit|" ${WRKSRC}/po/${file}.po
.endfor
	@${REINPLACE_CMD} '/destdir=/ s|=|=${STAGEDIR}|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applets/Utility
	${INSTALL_DATA} ${WRKSRC}/config-file/dictionary ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

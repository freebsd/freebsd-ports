# Created by: Juan Salaverria <rael@vectorstar.net>
# $FreeBSD$

PORTNAME=	gturing
PORTVERSION=	0.1.1
PORTREVISION=	20
CATEGORIES=	games gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/gturing/0.1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Turing machine simulator for GNOME 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gnomeprefix libgnomeui
USES=		gettext gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALLS_OMF=	yes

PORTDOCS=	AUTHORS NEWS ChangeLog TODO README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tapes/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

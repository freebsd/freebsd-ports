# ex:ts=8
# New ports collection makefile for:	babytrans
# Date created:			18 September 2002
# Whom:				Frederic Cambus
#
# $FreeBSD$
#

PORTNAME=	babytrans
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://fjolliton.free.fr/babytrans/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+/GNOME front-end for Babylon Translator .dic files

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk12 gnomehack gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

post-patch:
.for file in de es fr pt_BR
	@${REINPLACE_CMD} -e "s|CHARSET|ISO-8859-1|" \
		-e "s|ENCODING|8bit|" ${WRKSRC}/po/${file}.po
.endfor

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config-file/dictionary ${DATADIR}
	@${CAT} ${PKGMESSAGE} | ${SED} "s|%%DATADIR%%|${DATADIR}|"

.include <bsd.port.mk>

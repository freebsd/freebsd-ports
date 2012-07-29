# New ports collection makefile for:	games/gturing
# Date created:				08 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	gturing
PORTVERSION=	0.1.1
PORTREVISION=	18
CATEGORIES=	games gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/gturing/0.1/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Simple Turing machine simulator for GNOME 2

USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALLS_OMF=	yes

PORTDOCS=	AUTHORS COPYING NEWS ChangeLog TODO README INSTALL
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tapes/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

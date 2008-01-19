# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#   $MCom: ports/cad/oregano/Makefile,v 1.9 2007/07/23 19:25:26 mezz Exp $
#

PORTNAME=	oregano
PORTVERSION=	0.69.0
CATEGORIES=	cad gnome
MASTER_SITES=	http://gforge.lug.fi.uba.ar/frs/download.php/86/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Schematic capture and simulation of electrical circuits

USE_GNOME=	gnomehack gnomeprefix gtksourceview intlhack libglade2 \
		libgnomeui
USE_GETTEXT=	yes
USE_SCONS=	yes
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

BROKEN=	does not fetch

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall|${CFLAGS}|g" ${WRKSRC}/SConstruct

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/oregano
.for lang in C es fr
	@${MKDIR} ${PREFIX}/share/gnome/help/oregano/${lang}
	${INSTALL_DATA} ${WRKSRC}/help/${lang}/*.xml \
		${PREFIX}/share/gnome/help/oregano/${lang}
	@${MKDIR} ${PREFIX}/share/omf/oregano
	${INSTALL_DATA} ${WRKSRC}/help/${lang}/*.omf \
		${PREFIX}/share/omf/oregano
.endfor

.include <bsd.port.post.mk>

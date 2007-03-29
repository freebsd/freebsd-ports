# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#    $MCom: ports/cad/oregano/Makefile,v 1.7 2006/10/10 05:25:08 ahze Exp $

PORTNAME=	oregano
PORTVERSION=	0.60.0
PORTREVISION=	2
CATEGORIES=	cad gnome
MASTER_SITES=	http://gforge.lug.fi.uba.ar/frs/download.php/84/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Schematic capture and simulation of electrical circuits

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtksourceview intlhack libglade2 \
		libgnomeprintui libgnomeui
USE_SCONS=	yes
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall|${CFLAGS}|g ; \
		 s|'/share'|'/share/gnome'|g ; \
		 s|'share/applications'|'share/gnome/applications'|g ; \
		 s|'share/mime-info'|'share/gnome/mime-info'|g" ${WRKSRC}/SConstruct
	@${FIND} ${WRKSRC} -name "SConscript" | ${XARGS} ${REINPLACE_CMD} -e \
		"s|share/oregano|share/gnome/oregano|g"

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/oregano
.for lang in C es fr
	@${MKDIR} ${PREFIX}/share/gnome/help/oregano/${lang}
	${INSTALL_DATA} ${WRKSRC}/help/${lang}/*.xml \
		${PREFIX}/share/gnome/help/oregano/${lang}
	@${MKDIR} ${PREFIX}/share/gnome/omf/oregano
	${INSTALL_DATA} ${WRKSRC}/help/${lang}/*.omf \
		${PREFIX}/share/gnome/omf/oregano
.endfor
	${INSTALL_DATA} ${WRKSRC}/gnome-oregano.svg \
		${PREFIX}/share/gnome/pixmaps/gnome-oregano.svg

.include <bsd.port.post.mk>

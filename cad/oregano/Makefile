# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#

PORTNAME=	oregano
PORTVERSION=	0.50.0
CATEGORIES=	cad gnome
MASTER_SITES=	http://gforge.lug.fi.uba.ar/frs/download.php/80/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Schematic capture and simulation of electrical circuits

BUILD_DEPENDS=	scons:${PORTSDIR}/devel/scons

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gtksourceview intlhack libglade2 \
		libgnomeprintui libgnomeui
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall|${CFLAGS}|g ; \
		 s|'/share'|'/share/gnome'|g ; \
		 s|'gnome/apps/Applications'|'applications'|g ; \
		 /oregano\.xml/d" ${WRKSRC}/SConstruct
	@${FIND} ${WRKSRC} -name "SConscript" | ${XARGS} ${REINPLACE_CMD} -e \
		"s|share/oregano|share/gnome/oregano|g"

do-build:
	@cd ${BUILD_WRKSRC} && scons PREFIX=${PREFIX}

do-install:
	@cd ${BUILD_WRKSRC} && scons install PREFIX=${PREFIX}
	@${STRIP_CMD} ${PREFIX}/bin/oregano
	@${MKDIR} ${PREFIX}/share/gnome/oregano/models
	${INSTALL_DATA} ${WRKSRC}/data/models/*.model \
		${PREFIX}/share/gnome/oregano/models
	@${MKDIR} ${PREFIX}/share/gnome/oregano/samples
	${INSTALL_DATA} ${WRKSRC}/src/samples/*.oregano \
		${PREFIX}/share/gnome/oregano/samples
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
	${INSTALL_DATA} ${WRKSRC}/oregano.xml.in \
		${PREFIX}/share/mime/packages/oregano.xml
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>

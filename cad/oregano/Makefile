# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#   $MCom: ports/cad/oregano/Makefile,v 1.9 2007/07/23 19:25:26 mezz Exp $
#

PORTNAME=	oregano
PORTVERSION=	0.69.0
PORTREVISION=	2
CATEGORIES=	cad gnome
MASTER_SITES=	http://gforge.lug.fi.uba.ar/frs/download.php/86/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Schematic capture and simulation of electrical circuits

USE_GNOME=	gnomehack gnomeprefix gtksourceview intlhack libglade2 \
		libgnomeui
USE_GETTEXT=	yes
USE_SCONS=	yes
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-Wall|${CFLAGS}|g;s|%%PREFIX%%|${PREFIX}|;s|pkg-config|${LOCALBASE}/bin/pkg-config|g" ${WRKSRC}/SConstruct
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e "/^SConscript ('po\/SConscript')/d" ${WRKSRC}/SConstruct
.endif

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

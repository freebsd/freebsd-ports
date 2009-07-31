# New ports collection makefile for:	winefish
# Date created:		2005-09-09
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	winefish
DISTVERSION=	1.3.3
PORTREVISION=	6
CATEGORIES=	editors print
MASTER_SITES=	http://download.berlios.de/winefish/ \
		http://nivi.interfree.it/distfiles/winefish/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A LaTeX editor based on BlueFish

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	dos2unix:${PORTSDIR}/converters/unix2dos \
		gv:${PORTSDIR}/print/gv \
		latex:${PORTSDIR}/print/teTeX \
		tidy:${PORTSDIR}/www/tidy \
		xpdf:${PORTSDIR}/graphics/xpdf

MAN1=		winefish.1
MANCOMPRESSED=	no

CONFIGURE_ARGS+=	--with-freedesktop_org-menu=${GNOME_LOCALSTATEDIR}/applications --with-icon-path=${GNOME_LOCALSTATEDIR}/pixmaps
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui desktopfileutils gnomehier

OPTIONS=	CONTEXT	"Enable ConTexT support (Experimental)"	off \
		VNTEX	"Vietnamese TeX user"	off \
		UNIKEY_GTK	"Vietname Tex user with UnikeyGTK input method"	off

.include <bsd.port.pre.mk>

.if defined (WITH_CONTEXT)
CONFIGURE_ARGS+=	--with-context
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB=	IFNLS=
# vietnamese support
.if defined (WITH_UNIKEY_GTK) && !defined (WITH_VNTEX)
WITH_VNTEX=true
.endif

.if defined (WITH_VNTEX)
CONFIGURE_ARGS+=	--with-vntex
.if defined (WITH_UNIKEY_GTK)
CONFIGURE_ARGS+=	--with-unikey-gtk
.endif
.endif
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	IFNLS="@comment "
.endif

post-install:
	-@update-desktop-database
.if defined(NOPORTDOCS)
	${RM} ${DOCSDIR}/${PORTNAME}.html
	${RMDIR} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#   $MCom: ports/graphics/dia/Makefile,v 1.16 2007/10/11 02:49:12 mezz Exp $
#

PORTNAME=	dia
DISTVERSION=	0.97
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT=	Diagram creation program, similar to Visio

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack gnomeprefix libxslt libartlgpl2 intlhack \
		desktopfileutils
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl" \
		LOCALBASE="${LOCALBASE}"

MAN1=		dia.1
MANLANG=	"" fr

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
USE_GNOME+=	pygtk2
CONFIGURE_ARGS=	--with-python
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=		libgnomeui
INSTALLS_OMF=		yes
CONFIGURE_ARGS+=	--enable-gnome
PKGNAMESUFFIX=		-gnome
GNOME_ENABLED=		yes
PLIST_SUB+=		GNOME=""
.else
CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=		GNOME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/lib/intl.c
.if defined(NOPORTDOCS)
	@${FIND} ${WRKSRC}/doc -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(examples)||g ; s|$$(mkinstalldirs) $$(sysdoc)/examples||g ; \
		s|$$(mkinstalldirs) $$(sysdoc)||g'
.endif
.ifndef (GNOME_ENABLED)
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e \
		's,\(^GTK_LIBS.*\),\1 ${PTHREAD_LIBS}, ; \
		 s,\(^GTK_CFLAGS = \),\1 ${PTHREAD_CFLAGS} ,'
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl|${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl| ; \
	    	s|echo aout|echo elf|g' \
		${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>

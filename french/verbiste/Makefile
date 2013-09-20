# Created by: Dan Phillips <dan-ports@dp.id.au>
# $FreeBSD$

PORTNAME=	verbiste
PORTVERSION=	0.1.33
CATEGORIES=	french textproc
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	dereckson@gmail.com
COMMENT=	French verb conjugator/deconjugator

OPTIONS_DEFINE=	GTK2 GNOME

LICENSE=	GPLv2

USES=		pathfix pkgconfig iconv
USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack libxml2
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		french-conjugator.1 french-deconjugator.1
MAN3=		verbiste.3
MANLANG=	"" fr

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=--with-gtk-app
USE_GNOME+=	gtk20
PLIST_SUB+=	HASGTK=""
.else
PLIST_SUB+=	HASGTK="@comment "
.endif

.if ${PORT_OPTIONS:MGNOME}
CONFIGURE_ARGS+=--with-gnome-app
USE_GNOME+=	gnomeprefix libgnomeui
PLIST_SUB+=	HASGNOME=""
.else
PLIST_SUB+=	HASGNOME="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MGNOME}
USES+=		gettext
PLIST_SUB+=	HASGUI=""
.else
PLIST_SUB+=	HASGUI="@comment "
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR}
.for f in README *.java *.c
	${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}

.include <bsd.port.mk>

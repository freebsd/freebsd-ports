# New ports collection makefile for:	verbiste
# Date created:				16 November 2005
# Whom:					Dan Phillips <dan-ports@dp.id.au>
#
# $FreeBSD$
#

PORTNAME=	verbiste
PORTVERSION=	0.1.32
CATEGORIES=	french textproc
MASTER_SITES=	http://perso.b2b2c.ca/sarrazip/dev/

MAINTAINER=	dereckson@gmail.com
COMMENT=	French verb conjugator/deconjugator

OPTIONS=	GTK	"With GTK+ application"		no	\
		GNOME	"With GNOME application"	no

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack ltverhack libxml2
USE_ICONV=	yes
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		french-conjugator.1 french-deconjugator.1
MAN3=		verbiste.3
MANLANG=	"" fr

.include <bsd.port.pre.mk>

.if defined(WITH_GTK)
CONFIGURE_ARGS+=--with-gtk-app
USE_GNOME+=	gtk20
PLIST_SUB+=	HASGTK=""
.else
PLIST_SUB+=	HASGTK="@comment "
.endif

.if defined(WITH_GNOME)
CONFIGURE_ARGS+=--with-gnome-app
USE_GNOME+=	gnomeprefix libgnomeui
PLIST_SUB+=	HASGNOME=""
.else
PLIST_SUB+=	HASGNOME="@comment "
.endif

.if defined(WITH_GTK) || defined(WITH_GNOME)
USE_GETTEXT=	yes
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

.include <bsd.port.post.mk>

# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	xmorph
PORTVERSION=	2006.08.17
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/20060817
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A digital image warping program

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

CONFLICTS=	libmorph*

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
WANT_GNOME=	yes
USE_XORG=	xbitmaps x11 xaw xext
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-waili
USE_LDCONFIG=	yes

MAN1=		gtkmorph.1 xmorph.1
INFO=		xmorph

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=		gtk20
CONFIGURE_ARGS+=	--with-gtk=2
.else
CONFIGURE_ARGS+=	--without-gtkmorph
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${REINPLACE_CMD} -e 's|^LDFLAGS=|#LDFLAGS=|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/example && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

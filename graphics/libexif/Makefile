# Created by: Peter Schmiedeskamp <pschmied@qwest.net>
# $FreeBSD$

PORTNAME=	libexif
PORTVERSION=	0.6.21
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	marius@nuenneri.ch
COMMENT=	Library to read digital camera file meta-data

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS NLS

USES=		pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gnomehack ltverhack
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-docs
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ENV+=	am_cv_func_iconv=no
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|doc||g ; \
		 /^am__installdirs =/s|$$(docdir)||g ; \
		 /^install-data-am:/s|install-docDATA||g' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

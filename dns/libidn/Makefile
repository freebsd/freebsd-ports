# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	libidn
PORTVERSION=	1.27
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	Internationalized Domain Names command line tool

USES=		iconv pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

INFO=	libidn

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@image{components}||g' \
		${WRKSRC}/doc/libidn.texi
	@${REINPLACE_CMD} -e 's|$$(AUTOMAKE)|${TRUE}|' \
			-e 's|imagesdir = $$(infodir)|imagesdir = $$(docdir)|' \
		${WRKSRC}/doc/Makefile.in
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|install-data-am: install-imagesDATA install-info-am install-man|install-data-am: install-info-am install-man|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.mk>

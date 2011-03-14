# New ports collection makefile for:	libidn
# Date created:        	19.06.2003
# Whom:               	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libidn
PORTVERSION=	1.19
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gaod@hychen.org
COMMENT=	Internationalized Domain Names command line tool

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

INFO=	libidn

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
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
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|install-data-am: install-imagesDATA install-info-am install-man|install-data-am: install-info-am install-man|' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in FAQ NEWS README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.mk>

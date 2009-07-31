# New ports collection makefile for:	denemo
# Date created:				2001-02-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	denemo
PORTVERSION=	0.7.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Graphical score editor

USE_GNOME=	gnometarget gtk20 libxml2
USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	${CFLAGS} -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${GREP} -lR "<malloc.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'
	@${REINPLACE_CMD} -e \
		's|CXXFLAGS="$$CFLAGS|CXXFLAGS="$$DENEMO_CFLAGS|g ; \
		 s|-Wall -O2|-Wall $$CXXFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/icons|/pixmaps|g' ${WRKSRC}/pixmaps/Makefile.in
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e \
		's|install-data-am:.*|install-data-am:|' ${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS ChangeLog DESIGN GOALS NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

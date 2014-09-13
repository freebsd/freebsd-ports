# Created by: Chris D. Faulhaber <jedgar@fxp.org>
# $FreeBSD$

PORTNAME=	gtkgraph
PORTVERSION=	0.6.1
PORTREVISION=	13
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jedgar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphing calculator using GTK+

USES=		gettext gmake perl5
USE_GNOME=	imlib
USE_PERL5=	build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/gtkgraph \
		share/locale/fr/LC_MESSAGES/gtkgraph.mo \
		share/locale/ja/LC_MESSAGES/gtkgraph.mo

pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|-O2|${CFLAGS}| ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's|localedir)|DESTDIR)$$(&|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>

# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	gsnapshot
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/gould/${PORTNAME}/release%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ based screen capture

OPTIONS_DEFINE=	DOCS

USES=		pkgconfig gmake
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
AUTOMAKE_ARGS=	--add-missing
USE_GNOME=	gtk20 libwnck libxml2
USE_XORG=	x11 xmu

CFLAGS+=	-fPIC -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-lgmodule-2.0

PORTDOCS=	AUTHORS COPYING INSTALL README TODO

DESKTOP_ENTRIES=	"gsnapshot" \
			"Screen capture" \
			"" \
			"gsnapshot" \
			"Graphics;GTK;" \
			"false"

.include <bsd.port.options.mk>

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/install-sh ${WRKSRC}
	@${LN} -sf ${AUTOMAKE_DIR}/depcomp ${WRKSRC}
	@${LN} -sf ${AUTOMAKE_DIR}/missing ${WRKSRC}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

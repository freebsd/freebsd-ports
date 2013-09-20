# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icon-slicer
PORTVERSION=	0.3
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/icon-slicer/releases/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Utility for generating icon and cursor themes

LICENSE=	GPLv2

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/icon-slicer

PORTDOCS=	AUTHORS ChangeLog README TODO

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|examples||' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

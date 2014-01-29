# Created by: Alexander@Leidinger.net
# $FreeBSD$

PORTNAME=	xmms-gdancer
PORTVERSION=	0.4.6
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://www.travisemslander.com/gdancer/files/
DISTNAME=	gdancer-$(PORTVERSION)

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS Visualization plugin, displays dancing figures

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

USES=		gmake
USE_GNOME=	gtk12
USE_CSTD=	gnu89
USE_AUTOTOOLS=	libtool

PLIST_FILES=	lib/xmms/Visualization/gdancer.so

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2|@CFLAGS@| ; \
		 s|@GDK_PIXBUF_LIBS@||' ${WRKSRC}/src/Makefile.in

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Visualization
	(cd ${WRKSRC}/src/.libs && ${INSTALL_LIB} gdancer.so \
		${STAGEDIR}${PREFIX}/lib/xmms/Visualization)

.include <bsd.port.mk>

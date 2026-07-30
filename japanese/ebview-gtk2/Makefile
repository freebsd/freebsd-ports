PORTNAME=	ebview
DISTVERSION=	0.3.6
PORTREVISION=	21
CATEGORIES=	japanese
MASTER_SITES=	SF
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer
WWW=		https://ebview.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libeb.so:japanese/eb

USES=		gettext gmake gnome iconv:wchar_t localbase:ldflags pkgconfig \
		xorg
USE_CSTD=	gnu89
USE_GNOME=	gtk20 pangox-compat
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-eb-conf=${LOCALBASE}/etc/eb.conf

SUB_FILES=	ebview.desktop

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	(cd ${WRKDIR} && ${INSTALL_DATA} ${SUB_FILES} \
		${STAGEDIR}${DESKTOPDIR})
	(cd ${WRKSRC}/pixmaps && ${INSTALL_DATA} ebview.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ChangeLog README
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.post.mk>

# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gnochm
PORTVERSION=	0.9.11
PORTREVISION=	8
CATEGORIES=	deskutils python gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME viewer for CHM files

BROKEN=		Uses unknown GNOME component pygnomeextras
DEPRECATED=	Broken since update to gnome3
EXPIRATION_DATE=	2015-06-02

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/chm/_chmlib.so:${PORTSDIR}/textproc/pychm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils gettext gmake pathfix python shared-mime-info
USE_GNOME=	gnomeprefix intlhack pygnome2 pygtk2 pygnomeextras
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-mime-update
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnochm.schemas
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$(prefix)/share/man|$(prefix)/man|' ${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>

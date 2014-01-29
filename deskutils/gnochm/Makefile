# Created by: Radek Kozlowski <radek@raadradd.com>
# $FreeBSD$

PORTNAME=	gnochm
PORTVERSION=	0.9.11
PORTREVISION=	7
CATEGORIES=	deskutils python gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME viewer for CHM files

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/chm/_chmlib.so:${PORTSDIR}/textproc/pychm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USES=        pathfix gettext
USE_GNOME=	gnomeprefix intlhack pygnome2 pygtk2 pygnomeextras
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnochm.schemas
INSTALLS_OMF=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$(prefix)/share/man|$(prefix)/man|' ${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>

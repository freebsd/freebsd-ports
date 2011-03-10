# New ports collection makefile for:	gnochm
# Date created:				25 November 2004
# Whom:					Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	gnochm
PORTVERSION=	0.9.11
PORTREVISION=	6
CATEGORIES=	deskutils python gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNOME viewer for CHM files

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/chm/_chmlib.so:${PORTSDIR}/textproc/pychm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2 pygtk2 pygnomeextras
GNU_CONFIGURE=	yes
USE_PYTHON=	2.2+
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnochm.schemas
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$(prefix)/share/man|$(prefix)/man|' ${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>

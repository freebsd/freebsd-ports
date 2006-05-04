# New ports collection makefile for:	gnochm
# Date created:                		25 November 2004
# Whom:                    		Radek Kozlowski <radek@raadradd.com>
#
# $FreeBSD$
#

PORTNAME=	gnochm
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	deskutils python gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	A GNOME viewer for CHM files

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/chm/_chmlib.so:${PORTSDIR}/textproc/pychm
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/chm/_chmlib.so:${PORTSDIR}/textproc/pychm

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2 pygnomeextras
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnochm.schemas
INSTALLS_OMF=	yes

MAN1=		gnochm.1
MANLANG=	"" it
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's|@APPDATADIR@|@APPDATADIR@/gnome|' ${WRKSRC}/gnochm.py.in
	@${REINPLACE_CMD} -e 's|$(prefix)/share/man|$(prefix)/man|' ${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>

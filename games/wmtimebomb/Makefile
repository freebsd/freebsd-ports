# New ports collection makefile for:	wmtimebomb
# Version required:	0.2.0
# Date created:		10 August 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$

DISTNAME=	wmtimebomb.20
PKGNAME=	wmtimebomb-0.2.0
CATEGORIES=	games windowmaker
MASTER_SITES=	ftp://ftp.netmug.org/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		PropList.2:${PORTSDIR}/devel/libPropList \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gif.5:${PORTSDIR}/graphics/giflib \
		png.3:${PORTSDIR}/graphics/png
BUILD_DEPENDS=	${PREFIX}/lib/libWMaker.a:${PORTSDIR}/x11-wm/windowmaker

WRKSRC=		${WRKDIR}/wmtimebomb.app
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	${PERL} -pi -e 's,\@LOCALBASE\@,${LOCALBASE},g' ${WRKSRC}/Imakefile
	${PERL} -pi -e 's,\@X11BASE\@,${X11BASE},g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>

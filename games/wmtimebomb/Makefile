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

LIB_DEPENDS=	PropList.2:${PORTSDIR}/devel/libPropList \
		wraster.3:${PORTSDIR}/x11-wm/windowmaker

WRKSRC=		${WRKDIR}/wmtimebomb.app
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Imakefile

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/wmtimebomb
	${INSTALL_DATA} ${WRKSRC}/example.modefile ${PREFIX}/lib/X11/wmtimebomb

.include <bsd.port.mk>

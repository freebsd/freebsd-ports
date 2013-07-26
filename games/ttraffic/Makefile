# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttraffic
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	games tk
MASTER_SITES=	http://alpha.luc.ac.be/Research/Algebra/Members/Ttraffic/ \
		http://www.tobez.org/download/port-mirrors/games/ttraffic/

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	TTraffic - A Tcl/Tk version of Rush Hour

BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

NO_BUILD=	yes
USE_PERL5_BUILD=yes
USES=		shebangfix
SHEBANG_FILES=	ttraffic.tcl
SHEBANG_LANG=	wish
wish_OLD_CMD=	/usr/bin/wish
wish_CMD=		${LOCALBASE}/bin/wish8.4

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/local/share/ttraffic/|${DATADIR}/|' \
		${WRKSRC}/ttraffic.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ttraffic.tcl ${PREFIX}/bin/ttraffic
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ttraffic.levels ${DATADIR}

.include <bsd.port.mk>

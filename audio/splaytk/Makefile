# Created by: Brett Taylor <brett@peloton.physics.montana.edu>
# $FreeBSD$

PORTNAME=	splaytk
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk based interface for splay

LICENSE=	GPLv2

RUN_DEPENDS=	splay:audio/splay

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/splay-tk-${PORTVERSION}

USES=		tk:wrapper

DATADIR=	${PREFIX}/share/splay-tk

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/splay-tk.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/splay-tk.tcl ${STAGEDIR}${PREFIX}/bin/splay-tk
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xbm ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/splay-tk.gif ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

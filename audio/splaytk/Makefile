PORTNAME=	splaytk
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/players

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk based interface for splay

LICENSE=	GPLv2

DEPRECATED=	Abandonware, no development in 20 years and uses obsolete decoding library
EXPIRATION_DATE=2023-03-31

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

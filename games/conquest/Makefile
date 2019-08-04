# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	conquest
PORTVERSION=	7.2
CATEGORIES=	games
MASTER_SITES=	SF/conq/Conquest/Conquest%20${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player curses space warfare game similar to Netrek

LICENSE=	ART10

BROKEN=		unfetchable

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc/conquest \
		--datadir=${LOCALBASE}/share/conquest \
		--localstatedir=/var/games
CFLAGS+=	-Wno-return-type
GROUPS=		${PORTNAME}
MAKE_JOBS_UNSAFE=	yes
PORTDOCS=	README

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s|^.*@chgrp .(CONQGROUP) conq.*||g; \
		s|^.*@chmod 2771 conq.*||g;" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} "s/# include <termio.h>//g" ${WRKSRC}/c_defs.h
	@${REINPLACE_CMD} "s/-O2 -fPIC//g" ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/conqai ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/conqdriv ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/conqoper ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/conqstrat ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/conquest ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/conqrule ${STAGEDIR}${ETCDIR}/conqrule.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/conqnews.doc \
		${STAGEDIR}${DATADIR}/conqnews.doc.sample
	${INSTALL_DATA} ${WRKSRC}/conquest.doc ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}/var/games/conquest

.include <bsd.port.mk>

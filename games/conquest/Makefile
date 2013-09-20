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

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc/conquest \
		--datadir=${LOCALBASE}/share/conquest \
		--localstatedir=/var/games
CFLAGS+=	-Wno-return-type
GROUPS=		${PORTNAME}
BINGRP=		conquest
SHAREGRP=	conquest
MAKE_JOBS_UNSAFE=	yes
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} "s|^.*@chgrp .(CONQGROUP) conq.*||g; \
		s|^.*@chmod 2771 conq.*||g;" ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} "s/# include <termio.h>//g" ${WRKSRC}/c_defs.h
	${REINPLACE_CMD} "s/-O2 -fPIC//g" ${WRKSRC}/configure

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} -m 2550 ${WRKSRC}/conqai ${PREFIX}/sbin
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conqdriv ${PREFIX}/libexec
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conqoper ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/conqstrat ${PREFIX}/sbin
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conquest ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/conquest
	${INSTALL_DATA} ${WRKSRC}/conqrule \
		${PREFIX}/etc/conquest/conqrule.sample
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/conqnews.doc ${DATADIR}/conqnews.doc.sample
	${INSTALL_DATA} ${WRKSRC}/conquest.doc ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${SH} pkg-install ${PORTNAME} POST-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

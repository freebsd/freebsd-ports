# New ports collection makefile for:	conquest
# Date created:			Apr 9, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	conquest
PORTVERSION=	7.2
CATEGORIES=	games
MASTER_SITES=	http://www.radscan.com/conquest/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-player curses space warfare game similar to Netrek

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${LOCALBASE}/etc/conquest \
		--datadir=${LOCALBASE}/share/conquest \
		--localstatedir=/var/games
BINGRP=		conquest
SHAREGRP=	conquest

post-patch:
	${REINPLACE_CMD} "s|^.*@chgrp .(CONQGROUP) conq.*||g; \
		s|^.*@chmod 2771 conq.*||g;" ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} "s/# include <termio.h>//g" ${WRKSRC}/c_defs.h
	${REINPLACE_CMD} "s/-O2 -fPIC//g" ${WRKSRC}/configure

do-install:
	@${SH} pkg-install ${PORTNAME} PRE-INSTALL
	${INSTALL_PROGRAM} -m 2550 ${WRKSRC}/conqai ${PREFIX}/sbin
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conqdriv ${PREFIX}/libexec
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conqoper ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/conqstrat ${PREFIX}/sbin
	${INSTALL_PROGRAM} -m 2551 ${WRKSRC}/conquest ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/conquest
	${INSTALL_DATA} ${WRKSRC}/conqrule \
		${PREFIX}/etc/conquest/conqrule.sample
	${MKDIR} ${PREFIX}/share/conquest
	${INSTALL_DATA} ${WRKSRC}/conqnews.doc \
		${PREFIX}/share/conquest/conqnews.doc.sample
	${INSTALL_DATA} ${WRKSRC}/conquest.doc ${PREFIX}/share/conquest
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/conquest
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/conquest
.endif
	@${SH} pkg-install ${PORTNAME} POST-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

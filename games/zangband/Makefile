# New ports collection makefile for:   zangband
# Date created:        29 May 2000
# Whom:                Makoto YAMAKURA <makoto@pinpott.spnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	zangband
PORTVERSION=	2.6.2
CATEGORIES+=	games
MASTER_SITES=	ftp://clockwork.dementia.org/angband/Variant/ZAngband/ \
		ftp://ftp.sunet.se/pub/games/Angband/Variant/ZAngband/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	makoto@pinpott.spnet.ne.jp

USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/lib \
		--with-setgid=${SHAREGRP}

NO_CDROM=	Possible copyright infringement

WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/MESSAGE
PLIST_SUB+=	ANGBANDBIN=${ANGBANDBIN} ANGBANDLIB=${ANGBANDLIB}

SHAREOWN=	games
SHAREGRP=	games
BINOWN=		${SHAREOWN}
BINGRP=		${SHAREGRP}
BINMODE=	2755

ANGBANDLIB?=	lib/${PORTNAME}
ANGBANDBIN?=	bin/${PORTNAME}

pre-patch:
	@${PERL} -pi.orig -e 's|aclocal|${ACLOCAL}|; \
		s|autoheader|${AUTOHEADER}|; \
		s|automake|${AUTOMAKE}|; s|autoconf|${AUTOCONF}|' \
		${WRKSRC}/bootstrap

pre-configure:
	(cd ${WRKSRC} ; ${SH} bootstrap)

post-install:
	(cd ${PREFIX}/${ANGBANDLIB} && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} apex data ; \
		${CHMOD} 755 . ; \
		${CHMOD} -R ug+rw,o-rw * ; \
		${CHMOD} -R o+r help ; \
		${CHMOD} 1777 save user \
	)
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g;s|%%ANGBANDBIN%%|${ANGBANDBIN}|g;s|%%ANGBANDLIB%%|${ANGBANDLIB}|g" ${FILESDIR}/MESSAGE.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

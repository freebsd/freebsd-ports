# New ports collection makefile for:	ja-zangband
# Date Created:			31 May 2000
# Whom:				Makoto YAMAKURA <makoto@pinpott.spnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	zangband
PORTVERSION=	2.4.0${JA_VERSION}
CATEGORIES=	japanese games
MASTER_SITES=	ftp://clockwork.dementia.org/angband/Variant/ZAngband/ \
		ftp://ftp.sunet.se/pub/games/Angband/Variant/ZAngband/
DISTFILES=	${PORTNAME}-${E_VERSION:S/.//g}-src.zip \
		${JA_DISTFILE}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${E_VERSION:S/.//g}-src.zip

MAINTAINER=	makoto@pinpott.spnet.ne.jp

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qa
USE_XLIB=	yes

NO_CDROM=	Possible copyright infringement

WRKSRC=		${WRKDIR}/ZAngband
PKGMESSAGE=	${WRKDIR}/MESSAGE
PLIST_SUB+=	ANGBANDBIN=${ANGBANDBIN} ANGBANDLIB=${ANGBANDLIB}

SHAREOWN=	games
SHAREGRP=	games
BINOWN=		${SHAREOWN}
BINGRP=		${SHAREOWN}
BINMODE=	2755

MAKE_ARGS+=	ANGBANDLIB=${PREFIX}/${ANGBANDLIB} \
		JAPANESE_CFLAGS="-DJP -DEUC"
ANGBANDLIB?=	lib/j${PORTNAME}
ANGBANDBIN?=	bin/j${PORTNAME}

E_VERSION=	${PORTVERSION:S/${JA_VERSION}//}

PATCH_VERSION?=	020104
JA_VERSION=	.j${PATCH_VERSION}
JA_DISTFILE=	z${E_VERSION:S/.//g}j104src.tgz

pre-patch:
	(cd ${WRKSRC} ; ${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${JA_DISTFILE})
	(cd ${WRKSRC}/src ; ${PATCH} -p1 -l -s < ../zj${E_VERSION:S/.//g}.patch ; ${PATCH} -p1 -l -s < ${FILESDIR}/makefile-adjust.patch)

pre-build:
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${CP} ${WRKSRC}/src/makefile.std ${WRKSRC}/src/Makefile
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g;s|%%ANGBANDBIN%%|${ANGBANDBIN}|g;s|%%ANGBANDLIB%%|${ANGBANDLIB}|g" ${FILESDIR}/MESSAGE.in > ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/testing ${PREFIX}/${ANGBANDBIN}
	${MKDIR} ${PREFIX}/${ANGBANDLIB}
	${CP} -rp ${WRKSRC}/lib/* ${PREFIX}/${ANGBANDLIB}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/lib
.if defined(USE_Z_SCORES)
	test -f ${PREFIX}/${ANGBANDLIB}/apex/scores.raw || \
		${CP} ${PREFIX}/${ANGBANDLIB}/apex/z_scores.raw \
			${ANGBANDLIB}/apex/scores.raw
.else
	test -f ${PREFIX}/${ANGBANDLIB}/apex/scores.raw || \
		${TOUCH} ${PREFIX}/${ANGBANDLIB}/apex/scores.raw
.endif
	(cd ${PREFIX}/${ANGBANDLIB} && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} apex data ; \
		${CHMOD} 755 . ; \
		${CHMOD} -R ug+rw,o-rw * ; \
		${CHMOD} -R o+r help xtra ; \
		${CHMOD} 1777 save user \
	)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

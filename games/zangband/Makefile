# New ports collection makefile for:   zangband
# Date created:        29 May 2000
# Whom:                Makoto YAMAKURA <makoto@pinpott.spnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	zangband
PORTVERSION=	2.4.0${JP_VERSION}
PORTREVISION=	1
CATEGORIES+=	games
MASTER_SITES=	ftp://export.andrew.cmu.edu/angband/Variant/ \
		ftp://ftp.sunet.se/pub/games/Angband/Variant/ \
		http://www.geocities.co.jp/SiliconValley-SanJose/9606/zg/
DISTFILES=	zangband-${E_VERSION:S/.//g}-src.zip
.if defined(JAPANESE)
DISTFILES+=	zj${E_VERSION:S/.//g}ux-${PATCH_VERSION}.tgz
.endif
DIST_SUBDIR=	zangband
EXTRACT_ONLY=	zangband-${E_VERSION:S/.//g}-src.zip

MAINTAINER=	makoto@pinpott.spnet.ne.jp

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qa
USE_XLIB=	yes

NO_CDROM=	Possible copyright infringement

PKGDIR?=	${.CURDIR}/pkg
WRKSRC=		${WRKDIR}/ZAngband
PKGMESSAGE=	${WRKDIR}/MESSAGE
PLIST=		${WRKDIR}/PLIST
PLIST_SUB+=	ANGBANDBIN=${ANGBANDBIN} ANGBANDLIB=${ANGBANDLIB}

SHAREOWN=	games
SHAREGRP=	games
BINOWN=		games
BINGRP=		games
BINMODE=	2755

MAKE_ARGS+=	ANGBANDLIB=${PREFIX}/${ANGBANDLIB}
.if !defined(JAPANESE)
ANGBANDLIB?=	lib/zangband
ANGBANDBIN?=	bin/zangband
.else
ANGBANDLIB?=	lib/jzangband
ANGBANDBIN?=	bin/jzangband
.endif

E_VERSION=	${PORTVERSION:S/${JP_VERSION}//}
.if defined(JAPANESE)
PATCH_VERSION?=	000901
JP_VERSION=	.j${PATCH_VERSION}
PLIST_ADD=	${PKGDIR}/PLIST.ja
MAKE_ARGS+=	JAPANESE_CFLAGS="-DJP -DEUC"
.endif

pre-patch:
.if defined(JAPANESE)
	(cd ${WRKSRC} ; ${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/zj${E_VERSION:S/.//g}ux-${PATCH_VERSION}.tgz)
	(cd ${WRKSRC}/src ; ${PATCH} -p1 -l -s < ../zj${E_VERSION:S/.//g}.patch ; ${PATCH} -p1 -l -s < ${FILESDIR}/makefile-adjust.patch)
.endif
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

post-build:
	@${RM} -f ${PLIST}
.for i in ${PKGDIR}/PLIST.a ${PLIST_ADD} ${PKGDIR}/PLIST.b
	@${CAT} ${i} >> ${PLIST}
.endfor

.include <bsd.port.mk>

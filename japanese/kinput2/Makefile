# New ports collection makefile for:	kinput2-wnn4
# Version required:	2.0p4
# Date created:		19 Dec 1997
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	kinput2-v2-fix4
PKGNAME?=	ja-kinput2-wnn4-2.0.4
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/ 

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

PATCHDIR=	${.CURDIR}/../kinput2-wnn4/patches
FILESDIR=	${.CURDIR}/../kinput2-wnn4/files
NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

.if !defined(CANNA) && !defined(SJ3) && !defined(WNN4) && !defined(WNN6)
# For this port
WNN4=			yes
.endif
#
# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
.if defined(CANNA)
INPUT_METHOD+=		canna
LIB_INPUT_METHOD+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna
KINPUT2_DEF+=		-DUseCanna
.endif
.if defined(SJ3)
INPUT_METHOD+=		sj3
BUILD_INPUT_METHOD+=	sj3serv:${PORTSDIR}/japanese/sj3
KINPUT2_DEF+=		-DUseSj3
.endif
.if defined(WNN4)
INPUT_METHOD+=		wnn4
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
KINPUT2_DEF+=		-DUseWnn
.elif defined(WNN6)
INPUT_METHOD+=		wnn6
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
KINPUT2_DEF+=		-DUseWnn -DWnnLibDir=${LOCALBASE}/lib/wnn6
.endif
#
# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
INPUT_METHOD!=	echo ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif
#
# Redefine $(IMAKE_CMD) with $(PORT_IMAKE_DEFINES) in ${WRKSRC}/Kinput2.conf
MAKE_ENV+=	 PORT_IMAKE_DEFINES='${KINPUT2_DEF}'

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

post-install:
# For Wnn4 or Wnn6
	@if [ -e ${PKGDIR}/MESSAGE ]; then \
		${CAT} ${PKGDIR}/MESSAGE; \
	fi

.include <bsd.port.mk>

# New ports collection makefile for:	jvim
# Version required:	jvim2.0r+onew2.2.10
# Date created:		5 Sep 1997
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	jvim2.0r+onew2.2.10
PKGNAME?=	ja-jvim-2.0r
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Japan/onew/ \
		ftp://ftp.leo.chubu.ac.jp/pub/editor/jvim/

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

PATCHDIR=	${.CURDIR}/../jvim/patches
FILESDIR=	${.CURDIR}/../jvim/files
PLIST=		${.CURDIR}/../jvim/pkg/PLIST
MANLANG=	ja
MAN1=		jcat.1 jfold.1 jgrep.1 jvim.1
WRKSRC=		${WRKDIR}/jvim2.0r

# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
.if defined(CANNA)
INPUT_METHOD+=		canna
LIB_INPUT_METHOD+=	canna\\.1\\.:${PORTSDIR}/japanese/Canna
JPLIB+=			-lcanna
.endif
.if defined(WNN4)
INPUT_METHOD+=		wnn4
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
JPDEF+=			-DWNN_ISDIR
JPLIB+=			-ljd -lcrypt
.elif defined(WNN6)
INPUT_METHOD+=		wnn6
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
JPDEF+=			-DWNN_ISDIR
JPLIB+=			-ljd -lcrypt
.endif
#
# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
INPUT_METHOD!=	echo ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif
#
# For ONEW library
.if defined(INPUT_METHOD)
BUILD_INPUT_METHOD+=	${LOCALBASE}/lib/libonew${INPUT_METHOD}.a:${PORTSDIR}/japanese/onew${INPUT_METHOD}
JPDEF+=		-DONEW
# If we use ONEW libray, then -lonew*.a should appear
# before the other libraries.
JPLIB!=		echo ${JPLIB} | sed 's%^%-lonew${INPUT_METHOD} %'
.endif

pre-build:
	cd ${WRKSRC}/src; \
	${SED}	-e 's,%LOCALBASE%,${LOCALBASE},g' \
		-e 's,%X11BASE%,${X11BASE},g' \
			./makefile.junx > Makefile; \

do-build:
	cd ${WRKSRC}/src; make FreeBSD 'JPDEF=${JPDEF}' 'JPLIB=${JPLIB}'

do-install:
	cd ${WRKSRC}/src; make install

post-install:
	for file in jcat jgrep jfold jvim; do \
		strip ${LOCALBASE}/bin/$$file; \
	done

.include <bsd.port.mk>

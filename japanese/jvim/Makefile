# New ports collection makefile for:	jvim
# Date created:		5 Sep 1997
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jvim
PORTVERSION=	2.0r
PKGNAMESUFFIX=	${INPUT_METHOD}
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Japan/onew/ \
		ftp://ftp.leo.chubu.ac.jp/pub/editor/jvim/
DISTNAME=	${PORTNAME}${PORTVERSION}+onew2.2.10

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Japanized Vim

PATCHDIR=	${.CURDIR}/../jvim/files
FILESDIR=	${.CURDIR}/../jvim/files
PLIST=		${.CURDIR}/../jvim/pkg-plist
MANLANG=	ja
MAN1=		jcat.1 jfold.1 jgrep.1 jvim.1
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
.if defined(CANNA)
INPUT_METHOD+=	canna
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/Canna
JPLIB+=		-lcanna
.endif
.if defined(FREEWNN)
INPUT_METHOD+=	freewnn
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/wnn/ja_JP/rk/2B_ROMKANA:${PORTSDIR}/japanese/FreeWnn-lib
JPDEF+=		-DWNN_ISDIR
JPLIB+=		-ljd -lcrypt
.elif defined(WNN6)
INPUT_METHOD+=	wnn6
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6/2B_ROMKANA:${PORTSDIR}/japanese/onew${INPUT_METHOD}
JPDEF+=		-DWNN_ISDIR
JPLIB+=		-ljd -lcrypt
.elif defined(WNN7)
INPUT_METHOD+=	wnn7
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/wnn/ja_JP/rk.wnn7/2B_ROMKANA:${PORTSDIR}/japanese/onew${INPUT_METHOD}
JPDEF+=		-DWNN_ISDIR
JPLIB+=		-ljd -lcrypt
.endif

.include <bsd.port.pre.mk>

#
# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
INPUT_METHOD!=	${ECHO_CMD} ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif
#
# For ONEW library
.if defined(INPUT_METHOD)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew${INPUT_METHOD}.a:${PORTSDIR}/japanese/onew${INPUT_METHOD}
JPDEF+=		-DONEW
# If we use ONEW libray, then -lonew*.a should appear
# before the other libraries.
JPLIB!=		${ECHO_CMD} ${JPLIB} | sed 's%^%-lonew${INPUT_METHOD} %'
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
	${LN} -sf ${PREFIX}/bin/jvim2 ${PREFIX}/bin/jvim

post-install:
	for file in jcat jgrep jfold jvim; do \
		strip ${LOCALBASE}/bin/$$file; \
	done

.include <bsd.port.post.mk>

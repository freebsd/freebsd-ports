# New ports collection makefile for:    jvim3
# Version required:     3.0-j1.3j
# Date created:         98/11/17
# Whom:                 Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id: Makefile,v 1.7 1998/11/28 02:18:44 asami Exp $
#

DISTNAME=	vim
PKGNAME?=	ja-jvim-3.0.1.3j
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://dutepp0.et.tudelft.nl/pub/Unix/Editors/ \
		http://hp.vector.co.jp/authors/VA003457/vim/vim3/1.3j/
DISTFILES=	vim-3.0.tar.gz ${JPATCH}

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

USE_XLIB=	yes
LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

NO_LATEST_LINK=	YES	# waiting for jgrep, jfold, jcat
PATCHDIR=	${.CURDIR}/../jvim3/patches
FILESDIR=	${.CURDIR}/../jvim3/files
PLIST=		${.CURDIR}/../jvim3/pkg/PLIST
EXTRACT_ONLY=	vim-3.0.tar.gz
MAKEFILE=	makjunix.mak
MAN1=		jvim3.1

VERSION=	3.0.1.3j
JPATCH=		jvim.1.3j.tar.gz
PLIST_SUB=	VERSION=${VERSION}
PORT_DOCDIR=	${PREFIX}/share/doc/ja-jvim-${VERSION}
# -DUSE_X11 is the cause of a problem treating Japanese
MACHINE=	 -DBSD_UNIX -DUSE_LOCALE -DUSE_X11
CC=		cc -O -g -Wall -traditional -Dconst= -I${X11BASE}/include
LIBS=		-ltermlib -lxpg4 -L${PREFIX}/lib -L${X11BASE}/lib -lX11
# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
FEPOPT=		-DJP_DEF=\"EEE\"
#######
#  Direct connection to Canna
#######
.if defined(DIRECT_CANNA)
INPUT_METHOD=		-direct_canna
LIB_INPUT_METHOD=	canna.1:${PORTSDIR}/japanese/Canna
FEPOPT+=		-DCANNA
FEPLIBS=		-lcanna
FEPOBJS=		fepcanna.o
.else # DIRECT_CANNA
#######
# Connection by using ONEW library
#######
.if defined(CANNA)
INPUT_METHOD+=		canna
LIB_INPUT_METHOD+=	canna.1:${PORTSDIR}/japanese/Canna
FEPLIBS+=		-lcanna
.endif
.if defined(WNN4)
INPUT_METHOD+=		wnn4
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
FEPLIBS+=		-L${X11BASE}/lib -ljd -lcrypt
.elif defined(WNN6)
INPUT_METHOD+=		wnn6
BUILD_INPUT_METHOD+=	${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/Wnn
FEPLIBS+=		-L${X11BASE}/lib -ljd -lcrypt
.endif
#
# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
# 'echo' and 'sed' cannot replace by '${ECHO}' and '${SED}' in the next line
INPUT_METHOD!=	echo ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif
#
# For ONEW library
.if defined(INPUT_METHOD)
BUILD_INPUT_METHOD+=	${LOCALBASE}/lib/libonew${INPUT_METHOD}.a:${PORTSDIR}/japanese/onew${INPUT_METHOD}
FEPOPT+=	-DONEW
# If we use ONEW libray, then -lonew-* need appear
# before the other libraries in ${FEPLIBS}.
### 'sed' and echo cannot replace by '${SED}' and ${ECHO} in the next line
FEPLIBS!=	echo ${FEPLIBS} | sed 's%^%-lonew${INPUT_METHOD} %'
FEPOBJS=	feponew.o
.endif
.endif # DIRECT_CANNA
###
.if defined(FEPOBJS)
# In the case defining at least one of CANNA, WNN4, WNN6, DIRECT_CANNA
FEPOPT+=	-DFEPCTRL
.endif

post-extract:
	${EXTRACT_CMD} -C ${WRKSRC} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${JPATCH}

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/jvim.diff

do-build:
	cd ${WRKSRC}/src; \
	make -f ${MAKEFILE} 'FEPOPT=${FEPOPT}' 'FEPLIBS=${FEPLIBS}' \
		'FEPOBJS=${FEPOBJS}' 'MACHINE=${MACHINE}' 'CC=${CC}' \
		'LIBS=${LIBS}'

do-install:
	cd ${WRKSRC}/src; make -f ${MAKEFILE} install
	if [ -e ${PREFIX}/etc/jvim3rc ]; then \
		${MV} ${PREFIX}/etc/jvim3rc ${PREFIX}/etc/jvim3rc.bak; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/src/grep/grep ${PREFIX}/bin/jgrep
	${ECHO} "set fepctrl onewredraw" > ${PREFIX}/etc/jvim3rc
.if !defined(NOPORTDOCS)
.if defined(PORT_DOCDIR)
	${MKDIR} ${PORT_DOCDIR}
	for file in fj.txt differen.doc readme.doc uganda.jp \
			fepctrl.doc tutor/tutor.j; do \
		${INSTALL_DATA} ${WRKSRC}/doc.j/$$file ${PORT_DOCDIR}; \
	done

.endif
.endif

.include <bsd.port.mk>

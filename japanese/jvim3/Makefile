# New ports collection makefile for:    jvim3
# Date created:         98/11/17
# Whom:                 Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jvim
PORTVERSION=	3.0.j2.1a
PORTREVISION=	1
PKGNAMESUFFIX=	${INPUT_METHOD}
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.vim.org/pub/vim/unix/ \
		http://hp.vector.co.jp/authors/VA003457/vim/vim3/2.1a/
DISTFILES=	vim-3.0.tar.gz \
		${JPATCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Japanized Vim-3.0

NO_LATEST_LINK=	YES	# waiting for jgrep, jfold, jcat
PATCHDIR=	${.CURDIR}/../jvim3/files
FILESDIR=	${.CURDIR}/../jvim3/files
PLIST=		${.CURDIR}/../jvim3/pkg-plist
EXTRACT_ONLY=	vim-3.0.tar.gz
WRKSRC=		${WRKDIR}/vim
MAKEFILE=	makjunix.mak
MAN1=		jvim3.1

.include <bsd.port.pre.mk>

JPATCH=		jvim.2.1a.tar.gz
PLIST_SUB=	VERSION=${PORTVERSION}
PORT_DOCDIR=	${PREFIX}/share/doc/ja-jvim-${PORTVERSION}
# -DUSE_X11 is the cause of a problem treating Japanese
MACHINE=	-DBSD_UNIX -DUSE_LOCALE
CC=		cc ${CFLAGS} -Wall
LIBS=		-ltermlib -L${PREFIX}/lib 

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
MACHINE+=	-DUSE_X11
CC+=		-I${X11BASE}/include
LIBS+=		-L${X11BASE}/lib -lX11
.endif

# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
FEPOPT=		-DJP_DEF=\"EEE\"
#######
#  Direct connection to Canna
#######
.if defined(DIRECT_CANNA)
INPUT_METHOD+=	direct_canna
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/Canna
FEPOPT+=	-DCANNA
FEPLIBS=	-lcanna
FEPOBJS=	fepcanna.o
.else # DIRECT_CANNA
#######
# Connection by using ONEW library
#######
.if defined(CANNA)
INPUT_METHOD+=	canna
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/Canna
FEPLIBS+=	-lcanna
.endif
.if defined(FREEWNN)
INPUT_METHOD+=	freewnn
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
FEPLIBS+=	-L${LOCALBASE}/lib -ljd -lcrypt
.elif defined(WNN6)
INPUT_METHOD+=	wnn6
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6/2B_ROMKANA:${PORTSDIR}/japanese/onew${INPUT_METHOD}
FEPLIBS+=	-L${LOCALBASE}/lib -ljd -lcrypt
.elif defined(WNN7)
INPUT_METHOD+=	wnn7
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
RUN_DEPENDS+=	${LOCALBASE}/lib/wnn/ja_JP/rk.wnn7/2B_ROMKANA:${PORTSDIR}/japanese/onew${INPUT_METHOD}
FEPLIBS+=	-L${LOCALBASE}/lib -ljd -lcrypt
.endif
.endif # DIRECT_CANNA
#
.if defined(INPUT_METHOD)
# Make a value of INPUT_METHOD
## 'sed' in the next line cannot be replaced with '${SED}'
INPUT_METHOD!=	${ECHO_CMD} ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
FEPOPT+=	-DFEPCTRL
.if !defined(DIRECT_CANNA)
# For ONEW library
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew${INPUT_METHOD}.a:${PORTSDIR}/japanese/onew${INPUT_METHOD}
FEPOPT+=	-DONEW
# If we use ONEW libray, then -lonew-* needs appear
# before the other libraries in ${FEPLIBS}.
## 'sed' in the next line cannot be replaced with '${SED}'
FEPLIBS!=	${ECHO_CMD} ${FEPLIBS} | sed 's%^%-lonew${INPUT_METHOD} %'
FEPOBJS=	feponew.o
###
.endif
PLIST_SUB+=     HAS_JVIM3RC=""
.else
PLIST_SUB+=     HAS_JVIM3RC="@comment "
.endif

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}${JPATCH} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/jvim.diff

do-build:
	cd ${WRKSRC}/src; \
	make -f ${MAKEFILE} 'FEPOPT=${FEPOPT}' 'FEPLIBS=${FEPLIBS}' \
		'FEPOBJS=${FEPOBJS}' 'MACHINE=${MACHINE}' 'CC=${CC}' \
		'LIBS=${LIBS}'

do-install:
	cd ${WRKSRC}/src; make -f ${MAKEFILE} install
	${LN} -sf ${PREFIX}/bin/jvim3 ${PREFIX}/bin/jvim
	if [ -e ${PREFIX}/etc/jvim3rc ]; then \
		${MV} ${PREFIX}/etc/jvim3rc ${PREFIX}/etc/jvim3rc.bak; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/src/grep/grep ${PREFIX}/bin/jgrep
.if defined(INPUT_METHOD)
.if defined(DIRECT_CANNA)
	${ECHO_CMD} "set fepctrl" > ${PREFIX}/etc/jvim3rc
.else
	${ECHO_CMD} "set fepctrl onewredraw" > ${PREFIX}/etc/jvim3rc
.endif
.endif
.if !defined(NOPORTDOCS)
.if defined(PORT_DOCDIR)
	${MKDIR} ${PORT_DOCDIR}
	for file in cygwin.txt differen.doc fepctrl.doc readme.doc \
		termcap.dos uganda.jp vim-jp.htm vim32.ini tutor/tutor.j ; do \
		${INSTALL_DATA} ${WRKSRC}/doc.j/$$file ${PORT_DOCDIR}; \
	done

.endif
.endif

.include <bsd.port.post.mk>

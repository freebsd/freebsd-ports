# New ports collection makefile for:    rubytk
# Version required:     1.2.5
# Date created:         15 March 1999
# Whom:                 Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $Id$
#

DISTNAME=	ruby-${VERSION}
PKGNAME?=	rubytk-${VERSION}
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/${BRANCH_NAME}/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/${BRANCH_NAME}/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/${BRANCH_NAME}/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/${BRANCH_NAME}/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/${BRANCH_NAME}/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/${BRANCH_NAME}/

MAINTAINER?=	yasuf@big.or.jp

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
LIB_DEPENDS=	${TCL_LIB}.1:${PORTSDIR}/${TCL_CATEGORY}/tcl${TCL_VERSION} \
		${TK_LIB}.1:${PORTSDIR}/${TK_CATEGORY}/tk${TK_VERSION}

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/ext
CONFIGURE_ENV+=	TCL_LIB="${TCL_LIB}" TK_LIB="${TK_LIB}" \
		PREFIX="${PREFIX}" X11BASE="${X11BASE}"
PLIST_SUB+=	RUBY_ARCH="${RUBY_ARCH}"

RUBY_ARCH=	${ARCH}-freebsd${OSREL}

VERSION=	1.2.5
BRANCH_NAME=	1.2

# Set these vars as the version numbers (without decimal points) of Tcl/Tk
# you want to use with Ruby/Tk.
# e.g.: make TCL_VERSION=42 TK_VERSION=76 WITH_TCL_JP=yes build
TCL_VERSION?=	80
TK_VERSION?=	80
.if defined(WITH_TCL_JP)
TCL_CATEGORY=	japanese
TK_CATEGORY=	japanese
TCL_JP=		jp
.else
TCL_CATEGORY=	lang
TK_CATEGORY=	x11-toolkits
TCL_JP=		# empty
.endif

TCL_LIB=	tcl${TCL_VERSION}${TCL_JP}
TK_LIB=		tk${TK_VERSION}${TCL_JP}

RUBY=		${PREFIX}/bin/ruby
EXTS=		tcltklib tk

do-configure:
.for dir in ${EXTS}
	@${ECHO_MSG} "Configuring in ${dir}..."
	@cd ${WRKSRC}/${dir}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} extconf.rb
.endfor

do-build:
.for dir in ${EXTS}
	@${ECHO_MSG} "Building in ${dir}..."
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE} ${ALL_TARGET}
.endfor

do-install:
.for dir in ${EXTS}
	@${ECHO_MSG} "Installing in ${dir}..."
	@cd ${WRKSRC}/${dir}; ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}
.endfor

.include <bsd.port.mk>

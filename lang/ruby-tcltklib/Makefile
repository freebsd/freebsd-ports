# New ports collection makefile for:	ruby-tcltklib
# Date created:		15 March 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	tcltklib
PORTVERSION=	${RUBY_VERSION}
CATEGORIES+=	lang x11-toolkits ruby tcl${TCL_VERSION} tk${TK_VERSION}
MASTER_SITES=	${MASTER_SITE_RUBY}
#MASTER_SITE_SUBDIR=	${RUBY_VER}
DISTNAME=	ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER?=	yasuf@bsdclub.org

LIB_DEPENDS=	${TCL_LIB}.1:${PORTSDIR}/${TCL_CATEGORY}/tcl${TCL_VERSION} \
		${TK_LIB}.1:${PORTSDIR}/${TK_CATEGORY}/tk${TK_VERSION}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/ext/tcltklib
CONFIGURE_ARGS=	--with-tcllib="${TCL_LIB}" --with-tklib="${TK_LIB}" \
		--with-tcl-lib="${LOCALBASE}/lib/${TCL_DIR}" \
		--with-tk-lib="${LOCALBASE}/lib/${TK_DIR}" \
		--with-tcl-include="${LOCALBASE}/include/${TCL_DIR}" \
		--with-tk-include="${LOCALBASE}/include/${TK_DIR}" \
		--with-X11-dir="${X11BASE}"

# Set these vars as the version numbers (without decimal points) of Tcl/Tk
# you want to use with Ruby/Tk.
# e.g.: make TCL_VERSION=42 TK_VERSION=76 WITH_TCL_JP=yes build
TCL_VERSION?=	82
TK_VERSION?=	82
.if defined(WITH_TCLTK_JP)
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
TCL_DIR=	`echo "${TCL_LIB}" | ${SED} 's/\([0-9]\)\([0-9]\)/\1.\2/'`
TK_DIR=		`echo "${TK_LIB}"  | ${SED} 's/\([0-9]\)\([0-9]\)/\1.\2/'`

.include <bsd.port.pre.mk>

.if defined(PKGNAMEPREFIX)
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}
.else
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/tcltklib
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tcltklib/
	${MKDIR} ${RUBY_EXAMPLESDIR}/tcltklib/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_EXAMPLESDIR}/tcltklib/demo/
	${MKDIR} ${RUBY_DOCDIR}/tcltklib/ja
	${INSTALL_DATA} ${WRKSRC}/*.euc ${RUBY_DOCDIR}/tcltklib/ja/
.endif

.include <bsd.port.post.mk>

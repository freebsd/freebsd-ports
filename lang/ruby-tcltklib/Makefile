# New ports collection makefile for:	ruby-tcltklib
# Date created:		15 March 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	tcltklib
PORTVERSION=	${RUBY_PORTVERSION}
CATEGORIES+=	lang x11-toolkits ruby tcl${TCL_VERSION} tk${TK_VERSION}
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER?=	knu@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch
LIB_DEPENDS=	${TCL_LIB}.1:${PORTSDIR}/${TCL_CATEGORY}/tcl${TCL_VERSION} \
		${TK_LIB}.1:${PORTSDIR}/${TK_CATEGORY}/tk${TK_VERSION}

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
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

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR`/${PORTNAME} ${WRKDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/* ${RUBY_MODEXAMPLESDIR}/demo/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/*.euc ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>

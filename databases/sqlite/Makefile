# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	2.7.3
PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gerhard.haering@gmx.de

LIB_DEPENDS=	tcl${TCL_VER:S/.//}:${PORTSDIR}/lang/tcl${TCL_VER:S/.//}

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_REINPLACE=  YES
CONFIGURE_ARGS= --prefix=${PREFIX} --with-hints=freebsd.hints
ALL_TARGET=	all libtclsqlite.la
INSTALLS_SHLIB=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS+=	TCLSH=tclsh${TCL_VER}
MAKE_ENV+=	TCL_VER=${TCL_VER}
TCL_VER?=	8.3

DOCFILES=	arch.html arch.png c_interface.html changes.html \
		crosscompile.html download.html faq.html index.html \
		lang.html lemon.html mingw.html opcode.html report1.txt \
		speed.html sqlite.html tclsqlite.html vdbe.html

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" ${WRKSRC}/Makefile.in
	${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_VER}\"" >${WRKSRC}/freebsd.hints
	${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_VER:S/.//}\"" >>${WRKSRC}/freebsd.hints
	#${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 -pthread\"" >>${WRKSRC}/freebsd.hints

post-build:
	# Build the docs
	cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} doc

post-install:
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${DOCSDIR}
.for file in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

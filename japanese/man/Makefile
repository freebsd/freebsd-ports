# New ports collection makefile for:	jman - japanese man with EUC
# Version required:	1.1
# Date created:		4 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.9 1997/06/13 16:57:37 max Exp $
#

DISTNAME=	jp-man-1.1
CATEGORIES=	japanese
MASTER_SITES=	ftp://jaz.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		ftp://ports.jp.freebsd.org/pub/FreeBSD-jp/ports-jp/LOCAL_PORTS/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

#do not run-depend on mule because dependency will be pulled in to package
#and we don't know which one the user wants
RUN_DEPENDS=	${PREFIX}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MANLANG=	ja_JP.EUC
MAN1=		jcatman.1 jman.1 jmanpath.1 japropos.1 jwhatis.1 jmakewhatis.1
MANCOMPRESSED=	yes
JMANELDIR=	${PREFIX}/lib/mule/site-lisp/jman

# XPG4LIBPATH specifies the path name of the xpg4 library.
# The xpg4 library include setlocale() function and etc. for I18N,
# when using EUC code(e.g. ja_JP.EUC). At version 2.1.5 of FreeBSD or older,
# there isn't the xpg4 library in system, because include C library.
# But 2.2.0 or newer, the set of code for xpg4 was removed from C library,
# and included in new created xpg4 libray(/usr/lib/libxpg4*) .
# If your system have xpg4 library(libxpg4*) in /usr/lib, this patch 
# automatically apply to srource file. If your system have xpg4 library 
# in other directory, you must define XPG4LIBPATH. And if you don't want to
# use xpg4 library, you must define NOUSE_XPG4LIB. At default, you don't 
# have to define XPG4LIBPATH and NOUSE_XPG4LIB.
# See a make rule of target pre-patch for details.
# 
XPG4LIBPATH?=		/usr/lib

pre-patch:
	@${MKDIR} ${PATCHDIR}
	@${RM} -f ${PATCHDIR}/patch-aa
.if !defined(NOUSE_XPG4LIB)
	@${SED} -e "s,%XPG4LIBPATH%,${XPG4LIBPATH},g" \
		< ${FILESDIR}/patch-xpg4.tmpl > ${FILESDIR}/patch-xpg4
	@(for libfile in ${XPG4LIBPATH}/libxpg4*; do \
		if [ ! "$$libfile" = "" ]; then \
			ln -sf ${FILESDIR}/patch-xpg4 \
				${PATCHDIR}/patch-aa; \
			break 1; \
		fi; \
	done)
.else
	@ln -sf ${FILESDIR}/patch-noxpg4 ${PATCHDIR}/patch-aa
.endif

post-install:
	@${MKDIR} ${JMANELDIR}
	@${INSTALL_DATA} ${FILESDIR}/jman.el ${JMANELDIR}
	@${SETENV} CP=${CP} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

pre-clean:
	@${RM} -f ${PATCHDIR}/patch-aa ${FILESDIR}/patch-xpg4

.include <bsd.port.mk>

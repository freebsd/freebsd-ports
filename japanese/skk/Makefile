# New ports collection makefile for:	skk
# Version required:	9.6
# Date created:		04 Mar 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>
#
# $Id: Makefile,v 1.8 1997/06/08 12:55:02 asami Exp $
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

# Don't RUN_DEPENDS on mule because we don't know which version the
# user would want.  We can't omit the BUILD_DEPENDS because it needs
# to byte-compile .el files.
BUILD_DEPENDS=	mule:${PORTSDIR}/editors/mule

WRKSRC=		${WRKDIR}/skk-9.6
GNU_CONFIGURE=	yes

MAKE_FLAGS+=	EMACS=mule

STARTUP_SCRIPT= ${PREFIX}/etc/rc.d/skkserv.sh

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then \
		echo "Installing ${STARTUP_SCRIPT} file."; \
		echo "#!/bin/sh" > ${STARTUP_SCRIPT}; \
		echo "if [ -f ${PREFIX}/libexec/skkserv ]; then" >> \
			${STARTUP_SCRIPT}; \
		echo "  echo -n ' skkserv'; ${PREFIX}/libexec/skkserv" >> \
			${STARTUP_SCRIPT}; \
		echo "fi" >> ${STARTUP_SCRIPT}; \
		chmod 755 ${STARTUP_SCRIPT}; \
	fi
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
# Our makeinfo can't handle files with Japanese characters. :<
	install-info --section="The Emacs editor and associated tools" --entry="* Skk: (skk.info).		Yet another Japanese Inputting Method. (Japanese)" ${PREFIX}/info/skk.info ${PREFIX}/info/dir

.include <bsd.port.mk>

# ports collection makefile for:        Firebird BBS
# Date created:                         Sun Feb  4 22:48:06 CST 2001
# Whom:                                 Edward Chuang <edwardc@firebird.org.tw>
# $FreeBSD$

PORTNAME=		firebird
PORTVERSION=		3.0R
CATEGORIES=		chinese net
MASTER_SITES=		http://www.firebird.org.tw/download/ \
			ftp://ftp.firebird.org.tw/pub/Firebird/ \
			ftp://ftp4.firebird.org.tw/network/BBS/Firebird/
DISTNAME=		3.0-RELEASE

MAINTAINER=		edwardc@firebird.org.tw

WRKSRC=			${WRKDIR}/bbs/bbssrc
GNU_CONFIGURE=		yes
USE_BZIP2=			yes
IS_INTERACTIVE=		yes

pre-install:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/bbs.sh.example ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/bbs.sh.example startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/bbs.sh.example ${PREFIX}/etc/rc.d/bbs.sh.example; \
	fi
	@echo "======================================================================="
	@echo "Installnation Complete."
	@echo "======================================================================="
	@echo "please review ${PREFIX}/etc/rc.d/bbs.sh.example change bbsd port you want"
	@echo "then rename to ${PREFIX}/etc/rc.d/bbs.sh then:"
	@echo "use ${PREFIX}/etc/rc.d/bbs.sh { start | stop } to start the BBS service"
	@echo "full and complete document in ${PREFIX}/bbs/bbssrc/doc read before ask."

.include <bsd.port.mk>

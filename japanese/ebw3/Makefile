# New ports collection makefile for:    ebw3
# Version required:     0.2-b4
# Date created:         23 Jun 1997
# Whom:                 Hironori Ikura <hikura@kaisei.org>
#
# $Id: Makefile,v 1.1.1.1 1998/02/23 20:06:27 steve Exp $
#

DISTNAME=	ebw3-0.2-b4
PKGNAME=	ja-ebw3-0.2b4
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.imasy.or.jp/pub/unix/net/www/ebw3/

MAINTAINER=	hikura@kaisei.org

STARTUP_SCRIPT=	$(PREFIX)/etc/rc.d/ebw3d.sh.sample

post-install:
	${MKDIR} ${PREFIX}/www/cgi-bin
	${INSTALL} -c -o nobody -g nobody -m 555 ${WRKSRC}/cdsearch \
						$(PREFIX)/www/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/ebw3d.conf $(PREFIX)/etc/ebw3d.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/ebw3
	${INSTALL_DATA} ${WRKSRC}/INSTALL $(PREFIX)/share/doc/ebw3
	${INSTALL_DATA} ${WRKSRC}/README $(PREFIX)/share/doc/ebw3
	${INSTALL_DATA} ${FILESDIR}/README.port $(PREFIX)/share/doc/ebw3
	${INSTALL_DATA} ${FILESDIR}/README.access $(PREFIX)/share/doc/ebw3
.endif
	${INSTALL_SCRIPT} ${FILESDIR}/ebw3d.sh.sample $(PREFIX)/etc/rc.d

.include <bsd.port.mk>

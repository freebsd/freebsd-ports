# New ports collection makefile for:    ebw3
# Date created:         23 Jun 1997
# Whom:                 Hironori Ikura <hikura@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	ebw3
PORTVERSION=	${VERSION:S/-//}
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.imasy.or.jp/pub/unix/net/www/ebw3/
DISTNAME=	${PORTNAME}-${VERSION}

MAINTAINER=	hikura@kaisei.org
COMMENT=	Access to Japanese EPWING or Electric-Book based CD-ROM via HTTP

VERSION=	0.2-b4

STARTUP_SCRIPT=	$(PREFIX)/etc/rc.d/ebw3d.sh.sample

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

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

.include <bsd.port.post.mk>

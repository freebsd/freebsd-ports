# New ports collection makefile for:   makejvf-fkr-1.0
# Date created:        6 Oct 1999
# Whom:                Kentaro Inagaki <inagaki@tg.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	makejvf-fkr
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	asami/LOCAL_PORTS
DISTNAME=	makejvf-${PORTVERSION}-fkr
DIST_SUBDIR=    makejvf

MAINTAINER=	inagaki@tg.rim.or.jp
COMMENT=	Japanese Virtual Font file maker

INSTALL_TARGET=	install-all
DOCS=		README.1st README.txt \
		test1.tex test2.tex kuten2jis jy1mch.fd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>

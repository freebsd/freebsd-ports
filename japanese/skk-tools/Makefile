# New ports collection makefile for:	skk-tools
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	skk-tools
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/skk/tools/ \
		${MASTER_SITE_RINGSERVER}
MASTER_SITE_SUBDIR=	text/elisp/skk/tools
DISTNAME=	skktools-${PORTVERSION}

MAINTAINER=	matusita@FreeBSD.org

USE_BZIP2=	yes

GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/skk

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/READMEs/README.C ${DOCSDIR}/README.skktools

.include <bsd.port.mk>

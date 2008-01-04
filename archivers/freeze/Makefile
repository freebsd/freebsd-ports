# New ports collection makefile for:    freeze
# Date created:         20 Jul 1996
# Whom:                 lukin@okbmei.msk.su
#
# $FreeBSD$
#

PORTNAME=	freeze
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.warwick.ac.uk/pub/compression/ \
		http://www.rebootking.de/distfiles/ \
		http://ngsoftwareltd.com/freebsd/distfiles/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Compression program - often used in QNX

GNU_CONFIGURE=	yes
ALL_TARGET=	prog
MAKE_ARGS+=	CFLAGS="${CFLAGS} -I. -DCOMPAT" CC="${CC}"
MAN1=		freeze.1 melt.1 unfreeze.1 fcat.1 statist.1
PLIST_FILES=	bin/fcat bin/freeze bin/melt bin/statist bin/unfreeze
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

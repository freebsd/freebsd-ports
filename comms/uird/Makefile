# New ports collection makefile for:	uird
# Date created:		2005-11-21
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	uird
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	http://kbinstuff.googlepages.com/ \
		http://redundancy.redundancy.org/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	The Universal IR Receiver Daemon

USE_GMAKE=	yes
USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/uird
PORTDOCS=	Documentation

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}\ $${CFLAGS}|; /strip/d' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uird ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Ports collection makefile for:  gnake
# Date created:                   2011/02/20
# Whom:                           chinsan
#
# $FreeBSD$
#

PORTNAME=	gnake
PORTVERSION=	0.94b
CATEGORIES=	games
MASTER_SITES=	LOCAL/chinsan \
		http://lightless.org/files/
DISTNAME=	Gnake.${PORTVERSION}

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	A Nibbles clone for GNU/Linux and *BSD

LICENSE=	GPLv2
LDFLAGS+=	-L${LOCALBASE}/lib -lncurses
CFLAGS+=	-Wall

WRKSRC=		${WRKDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} \
		${WRKSRC}/gnake.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

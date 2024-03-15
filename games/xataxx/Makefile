PORTNAME=	xataxx
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Strategy game of position and movement for X Window System

LICENSE=	NONE

DEPRECATED=	No available WWW
EXPIRATION_DATE=2024-03-15

USES=		imake tar:Z xorg
USE_XORG=	x11 xext

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.post.mk>

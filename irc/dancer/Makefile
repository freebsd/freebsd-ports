PORTNAME=	dancer
PORTVERSION=	4.16
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC bot written in C for UNIX, Windows, and AmigaOS

PATCH_WRKSRC=		${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
MAKE_ARGS+=	CSPECIAL="${CFLAGS}" LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-lm
CPP=		#
USE_CSTD=	gnu89

CONFLICTS_INSTALL=	p5-Dancer

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/../${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/../example && ${INSTALL_DATA} \
		dancer.config dancer.users \
		dancer.funcs dancer.explain ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

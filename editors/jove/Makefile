# Created by: jkh
# $FreeBSD$

PORTNAME=	jove
PORTVERSION=	4.16
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/moraes/jove/ \
		LOCAL/simon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jonathan's Own Version of Emacs

LICENSE=	JOVE
LICENSE_NAME=	JOVE License
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		groff ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
# Fix collisions with getline(3)
	@${REINPLACE_CMD} 's|[[:<:]]getline[[:>:]]|get_line|g' ${WRKSRC}/*.c ${WRKSRC}/*.h

.include <bsd.port.mk>

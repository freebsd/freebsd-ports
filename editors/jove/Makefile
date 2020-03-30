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

USES=		ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXTRADOCS
EXTRADOCS_DESC=	Build and install cmds.doc
EXTRADOCS_USES=	groff
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

post-patch:
# Fix collisions with getline(3)
	@${REINPLACE_CMD} 's|[[:<:]]getline[[:>:]]|get_line|g' ${WRKSRC}/*.c ${WRKSRC}/*.h

post-patch-EXTRADOCS-off:
	@${REINPLACE_CMD} -E 's|^(all:.*) doc/cmds\.doc$$|\1|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|^CMDS.DOC = .*|CMDS.DOC=|' ${WRKSRC}/Makefile

.include <bsd.port.mk>

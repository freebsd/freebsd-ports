PORTNAME=	jove
PORTVERSION=	4.16
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/moraes/jove/ARCHIVE/4.16/ \
		LOCAL/simon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jonathan's Own Version of Emacs

LICENSE=	JOVE
LICENSE_NAME=	JOVE License
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	No upstream update in last 23 years
EXPIRATION_DATE=	2024-01-16

USES=		ncurses

MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXTRADOCS
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

EXTRADOCS_DESC=	Build and install cmds.doc
EXTRADOCS_USES=	groff

post-patch:
# Fix collisions with getline(3)
	@${REINPLACE_CMD} 's|[[:<:]]getline[[:>:]]|get_line|g' ${WRKSRC}/*.c ${WRKSRC}/*.h

post-patch-EXTRADOCS-off:
	@${REINPLACE_CMD} -E 's|^(all:.*) doc/cmds\.doc$$|\1|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|^CMDS.DOC = .*|CMDS.DOC=|' ${WRKSRC}/Makefile

.include <bsd.port.mk>

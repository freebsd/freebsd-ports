PORTNAME=	ballerburg
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
CATEGORIES=	games
MASTER_SITES=	https://framagit.org/baller/ballerburg/-/archive/${DISTVERSIONPREFIX}${DISTVERSION}/ \
		LOCAL/ehaupt:icons
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-icons-1${EXTRACT_SUFX}:icons

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Two players, two castles, and a hill in between
WWW=		https://baller.frama.io/

LICENSE=	GPLv3+

USES=		cmake:noninja localbase:ldflags sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes

LDFLAGS+=	-lintl

DESKTOP_ENTRIES=	"Ballerburg" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/ballerburg.png" \
			"${PORTNAME}" \
			"" \
			false

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-runtime

post-install:
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-icons-1/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>

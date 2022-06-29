PORTNAME=	vt100-art-and-animations
DISTVERSION=	2020.04.09
MASTER_SITES=	https://freebsd.lxxl.us/distfiles/${PORTNAME}-${DISTVERSION}/ \
		http://www.grosbein.net/freebsd/distfiles/ \
		LOCAL/eugen
#		http://artscene.textfiles.com/archives/
CATEGORIES=	games
DISTNAME=	vt100
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	VT100 art and animations

LICENSE=	UNKNOWN
LICENSE_NAME=	Unknown
LICENSE_TEXT=	The license is unknown.
LICENSE_PERMS=	auto-accept

USES=		zip

RUN_DEPENDS=	slowcat:textproc/slowcat

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

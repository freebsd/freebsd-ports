# $FreeBSD$

PORTNAME=	hp2100
DISTVERSION=	3.11-0.29
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/hp/releases/:src \
		http://simh.trailing-edge.com/hp/docs/:app \
		http://www.ml1.org.uk/distfiles/:src \
		http://www.ml1.org.uk/distfiles/:app
PKGNAMEPREFIX=	simh-
DISTFILES=	HP2100-source-release-${DISTVERSION:E}.zip:src
DIST_SUBDIR=	simh-hp
EXTRACT_ONLY=	HP2100-source-release-${DISTVERSION:E}.zip

MAINTAINER=	bob@eager.cx
COMMENT=	Emulates classic HP 2100 computers

LICENSE=	SIMHv1
LICENSE_NAME=	SIMH License
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${LOCALBASE}/share/doc/hpdoc/simh_doc.pdf:emulators/simh-hpdoc

USES=		gmake dos2unix zip

NO_WRKSUBDIR=	yes

CONFLICTS_INSTALL=	simh-3.[789]*
DOS2UNIX_GLOB=	*.c *.h *.txt *.mak makefile

SUB_FILES=	hp2100.1

.include <bsd.port.pre.mk>

do-build:
	(cd ${WRKSRC}; GCC="${CC}" ${GMAKE} -C SCP hp2100)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hp2100 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/hp2100.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/SCP/doc/*.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/SCP/doc/hp2100_guide.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>

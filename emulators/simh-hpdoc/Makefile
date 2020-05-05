# $FreeBSD$

PORTNAME=	hpdoc
DISTVERSION=	3.11.0
CATEGORIES=	emulators
MASTER_SITES=	http://simh.trailing-edge.com/hp/releases/:src \
		http://simh.trailing-edge.com/hp/docs/:app \
		http://www.ml1.org.uk/distfiles/:src \
		http://www.ml1.org.uk/distfiles/:app
PKGNAMEPREFIX=	simh-
DISTFILES=	HP2100-source-release-29.zip:src \
		HP3000-source-release-8.zip:src \
		running_hp_2000_tsb.pdf:app \
		hp_1000_io_simulation.pdf:app
DIST_SUBDIR=	simh-hp
EXTRACT_ONLY=	HP2100-source-release-29.zip \
		HP3000-source-release-8.zip

MAINTAINER=	bob@eager.cx
COMMENT=	Documentation for emulators of classic HP 2100 and HP 3000 computers

LICENSE=	SIMHv1
LICENSE_NAME=	SIMH License
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	simh-3.[789]*

OPTIONS_DEFINE=	APPNOTES
OPTIONS_DEFAULT=	APPNOTES
OPTIONS_SUB=	yes
APPNOTES_DESC=	Install application notes

SUB_FILES=	hpdoc.1

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/SCP/doc/simh_doc.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/SCP/doc/simh_supplement.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/hpdoc.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-APPNOTES-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/running_hp_2000_tsb.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/hp_1000_io_simulation.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

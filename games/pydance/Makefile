# Created by: Rudolf Polzer <freebsd-dr@durchnull.de>
# $FreeBSD$

PORTNAME=	pydance
PORTVERSION=	1.1.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://people.freebsd.org/~sylvio/pydance/ \
		http://icculus.org/pyddr/ \
		http://www.informatik.uni-frankfurt.de/~polzer/distfiles/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${SONGS}
DIST_SUBDIR=	pydance
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dancing simulation game similar to the kind in arcades

BUILD_DEPENDS=	${PYGAME}
RUN_DEPENDS=	${PYGAME}

USES=		python:2.7 shebangfix
SHEBANG_FILES=	pydance.py utils/findbpm.py
USE_PYTHON=	distutils noegginfo
SUB_FILES=	pkg-message

SONGS=		forkbomb.ogg forkbomb.dance forkbomb-bg.jpg forkbomb-banner.png \
		6jan.ogg 6jan.dance 6jan-bg.jpg 6jan-banner.png synrg.ogg \
		synrg.dance synrg-bg.png pydance-cdtitle.png

DOCFILES=	BUGS CREDITS ChangeLog HACKING INSTALL LICENSE README TODO \
		docs/dance-spec.txt docs/dwi-hall-of-shame.txt \
		docs/ksf-format.txt docs/manual.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${LOCALBASE}/etc," ${WRKSRC}/constants.py

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/pydance/songs
	${INSTALL_SCRIPT} ${WRKSRC}/utils/findbpm.py ${STAGEDIR}${PREFIX}/bin/findbpm
	(cd ${WRKSRC} && for MODULE in *.py; do test "$$MODULE" = "setup.py" -o \
		"$$MODULE" = "pydance.py" || ${INSTALL_DATA} $$MODULE \
		${STAGEDIR}${PREFIX}/share/games/pydance/$$MODULE || exit 1; done)
	${INSTALL_SCRIPT} ${WRKSRC}/pydance.py ${STAGEDIR}${PREFIX}/share/games/pydance
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "themes images sound" \
		${STAGEDIR}${PREFIX}/share/games/pydance)
	${INSTALL_MAN} ${WRKSRC}/docs/man/findbpm.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/man/pydance.6 ${STAGEDIR}${MANPREFIX}/man/man6
	${LN} -sf ${PREFIX}/share/games/pydance/pydance.py \
		${STAGEDIR}${PREFIX}/bin/pydance
	${INSTALL_DATA} ${WRKSRC}/pydance.posix.cfg \
		${STAGEDIR}${PREFIX}/etc/pydance.cfg.sample
	(cd ${_DISTDIR} && ${INSTALL_DATA} ${SONGS} \
		${STAGEDIR}${PREFIX}/share/games/pydance/songs)
	(cd ${STAGEDIR}${PREFIX}/share/games/pydance/songs && ${MV} \
		pydance-cdtitle.png pydance.png)

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} images ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

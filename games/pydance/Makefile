# New ports collection makefile for:    pydance
# Date created:                         26 October 2003
# Whom:                                 Rudolf Polzer <freebsd-dr@durchnull.de>
#
# $FreeBSD$
#

PORTNAME=	pydance
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/pyddr/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz ${SONGS}
DIST_SUBDIR=	pydance
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	freebsd-dr@durchnull.de
COMMENT=	Dancing simulation game similar to the kind in arcades

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GZIP=	yes
USE_REINPLACE=	yes

.if !defined(WITHOUT_PYDANCE_SONGS)
PLIST_SUB=	SONGS=""
SONGS=		forkbomb.ogg forkbomb.dance forkbomb-bg.jpg forkbomb-banner.png 6jan.ogg 6jan.dance 6jan-bg.jpg 6jan-banner.png synrg.ogg synrg.dance synrg-bg.png pydance-cdtitle.png
.else
PLIST_SUB=	SONGS="@comment "
SONGS=
.endif

PKGMESSAGE=	${WRKDIR}/.pkg-message

MAN1=		findbpm.1
MAN6=		pydance.6

DOCFILES=	BUGS CREDITS ChangeLog HACKING INSTALL LICENSE README TODO docs/dance-spec.txt docs/dwi-hall-of-shame.txt docs/ksf-format.txt

post-patch:
	${REINPLACE_CMD} -e "s,/etc,${LOCALBASE}/etc," ${WRKSRC}/constants.py
do-install:
	${MKDIR} ${PREFIX}/share/games/pydance
	${MKDIR} ${PREFIX}/share/games/pydance/songs
	cd ${WRKSRC} && ${INSTALL_SCRIPT} utils/findbpm.py ${PREFIX}/bin/findbpm
	cd ${WRKSRC} && for MODULE in *.py; do test "$$MODULE" = "setup.py" -o "$$MODULE" = "pydance.py" || ${INSTALL_DATA} $$MODULE ${PREFIX}/share/games/pydance/$$MODULE || exit 1; done
	cd ${WRKSRC} && ${INSTALL_SCRIPT} pydance.py ${PREFIX}/share/games/pydance/pydance.py
	cd ${WRKSRC} && ${FIND} themes/ images/ sound/ -type d -exec ${MKDIR} ${PREFIX}/share/games/pydance/{} \;
	cd ${WRKSRC} && ${FIND} themes/ images/ sound/ -type f -exec ${INSTALL_DATA} {} ${PREFIX}/share/games/pydance/{} \;
	cd ${WRKSRC} && ${INSTALL_MAN} docs/man/findbpm.1 ${MANPREFIX}/man/man1/
	cd ${WRKSRC} && ${INSTALL_MAN} docs/man/pydance.6 ${MANPREFIX}/man/man6/
	${LN} -sf ${PREFIX}/share/games/pydance/pydance.py ${PREFIX}/bin/pydance
	cd ${WRKSRC} && ${INSTALL_DATA} pydance.posix.cfg ${PREFIX}/etc/pydance.cfg.sample
.if !defined(WITHOUT_PYDANCE_SONGS)
	for SONG in ${SONGS}; do ${INSTALL_DATA} ${_DISTDIR}/$$SONG ${PREFIX}/share/games/pydance/songs; done
	${MV} ${PREFIX}/share/games/pydance/songs/pydance-cdtitle.png ${PREFIX}/share/games/pydance/songs/pydance.png
.endif

pre-install:
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

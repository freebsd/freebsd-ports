# Created by: Rudolf Polzer <freebsd-dr@durchnull.de>
# $FreeBSD$

PORTNAME=	pydance
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://people.freebsd.org/~sylvio/pydance/ \
		http://icculus.org/pyddr/ \
		http://offload1.icculus.org/pyddr/ \
		http://www.informatik.uni-frankfurt.de/~polzer/distfiles/
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz ${SONGS}
DIST_SUBDIR=	pydance
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dancing simulation game similar to the kind in arcades

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_NOEGGINFO=	yes

PLIST_SUB=	SONGS=""
SONGS=		forkbomb.ogg forkbomb.dance forkbomb-bg.jpg forkbomb-banner.png 6jan.ogg 6jan.dance 6jan-bg.jpg 6jan-banner.png synrg.ogg synrg.dance synrg-bg.png pydance-cdtitle.png

SUB_FILES=	pkg-message

MAN1=		findbpm.1
MAN6=		pydance.6

DOCFILES=	BUGS CREDITS ChangeLog HACKING INSTALL LICENSE README TODO docs/dance-spec.txt docs/dwi-hall-of-shame.txt docs/ksf-format.txt docs/manual.html

NO_STAGE=	yes
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
	for SONG in ${SONGS}; do ${INSTALL_DATA} ${_DISTDIR}/$$SONG ${PREFIX}/share/games/pydance/songs; done
	${MV} ${PREFIX}/share/games/pydance/songs/pydance-cdtitle.png ${PREFIX}/share/games/pydance/songs/pydance.png

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/images
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} docs/images/* ${DOCSDIR}/images
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

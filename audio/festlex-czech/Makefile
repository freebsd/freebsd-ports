PORTNAME=	festlex-czech
PORTVERSION=	0.2.1
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.freebsoft.org/pub/projects/festival-czech/
DISTNAME=	festival-czech-${PORTVERSION}
DIST_SUBDIR=	festival

MAINTAINER=	valtri@civ.zcu.cz
COMMENT=	Czech language support for Festival

FHOME=		${PREFIX}/share/festival
NO_BUILD=	yes
rulez=		czech-debug.scm czech-mbrola.scm czech-unisyn.scm czech.scm
lexicons=	czech-lexicon.scm czech-lexicon.out

post-patch:
	${MV} ${WRKSRC}/czech.scm ${WRKSRC}/czech.scm.in
	${SED} -e "s,@FESTIVAL_TARGET_DIR@,${FHOME}/lib/dicts," ${WRKSRC}/czech.scm.in > ${WRKSRC}/czech.scm

post-install:
	${MKDIR} ${STAGEDIR}${FHOME}/lib/dicts/
	${INSTALL} -m 644 ${rulez:C/^/${WRKSRC}\//} ${STAGEDIR}${FHOME}/lib/
	${INSTALL} -m 644 ${lexicons:C/^/${WRKSRC}\//} ${STAGEDIR}${FHOME}/lib/dicts/

.include <bsd.port.mk>

# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.0.R.1
CATEGORIES=	hungarian textproc
#MASTER_SITES=	http://www.szofi.hu/gnu/magyarispell/
MASTER_SITES=	http://magyarispell.sourceforge.net/
DISTNAME=	${PORTNAME}-1.0-RC1

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Improved Hungarian spelling checker

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes

MAN1=		hunspell.1
MAN4=		hunspell.4

PORTDOCS=	OLVASS.EL README README.myspell

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD-4.x at this time"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/hunspell.cxx

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.4 ${PREFIX}/man/man4
	${INSTALL_PROGRAM} ${WRKSRC}/hunspell ${PREFIX}/bin
	${LN} -s ${PREFIX}/bin/hunspell ${PREFIX}/bin/hunstem
	${MKDIR} ${PREFIX}/share/myspell/ && \
	${INSTALL_DATA} ${WRKSRC}/hu_HU.dic \
	${PREFIX}/share/myspell/ && \
	${INSTALL_DATA} ${WRKSRC}/hu_HU.aff \
	${PREFIX}/share/myspell/
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/magyar.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/hungarian.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/default.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/magyar.aff
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/hungarian.aff
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/default.aff
	${INSTALL_DATA} ${WRKSRC}/dictionary.lst \
	${PREFIX}/share/myspell/default.lst
	${LOCALBASE}/bin/msgfmt -o ${WRKSRC}/hunspell.mo ${WRKSRC}/hunspell.po
	${MKDIR} ${PREFIX}/share/locale/hu/LC_MESSAGES/ && \
	${INSTALL_DATA} ${WRKSRC}/hunspell.mo ${PREFIX}/share/locale/hu/LC_MESSAGES/

.ifndef(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

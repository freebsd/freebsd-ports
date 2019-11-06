# Created by: Seth Kingsley <sethk@osd.bsdi.com>
# $FreeBSD$

PORTNAME=	kdrill
PORTVERSION=	6.5
CATEGORIES=	japanese
MASTER_SITES=	http://www.bolthole.com/kdrill/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to quiz you on the meanings of Kanji

RUN_DEPENDS=	xjdic:japanese/edict

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

DATADIR=	${PREFIX}/share/dict/kdrill

post-build:
	@(cd ${WRKSRC}/makedic && ${DO_MAKE_BUILD} ${ALL_TARGET})

post-install:
.for i in makedic makeedict
	(cd ${WRKSRC}/makedic && ${INSTALL_PROGRAM} ${i} \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/makedic && ${INSTALL_MAN} ${i}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for i in fullkatahira.edic hira.edic hiraplus.edic kata.edic kataplus.edic
	(cd ${WRKSRC}/makedic && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>

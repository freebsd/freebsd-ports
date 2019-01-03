# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	aspell
MASTER_SITES=	https://j3e.de/ispell/igerman98/dict/
PORTVERSION=	20161207
PORTREVISION=	1
CATEGORIES=	german textproc
DISTNAME=	igerman98-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Aspell German dictionary

USES=		gmake tar:bzip2
ALL_TARGET=	aspell/de_DE.rws aspell/de_AT.rws aspell/de_CH.rws

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/aspell \
		${STAGEDIR}${PREFIX}/lib/aspell-0.60
.for lang in de_DE de_AT de_CH
	${INSTALL_DATA} ${WRKSRC}/aspell/${lang}.dat \
	    ${WRKSRC}/aspell/${lang}_affix.dat \
	    ${WRKSRC}/aspell/${lang}.multi \
	    ${STAGEDIR}${PREFIX}/lib/aspell-0.60
	${INSTALL_DATA} ${WRKSRC}/aspell/${lang}.rws \
	 ${STAGEDIR}${PREFIX}/share/aspell
.endfor
	${ECHO} "add de_DE.multi" > ${STAGEDIR}${PREFIX}/share/aspell/deutsch.alias
	${ECHO} "add de_DE.multi" > ${STAGEDIR}${PREFIX}/share/aspell/german.alias
	${ECHO} "add de_CH.multi" > ${STAGEDIR}${PREFIX}/share/aspell/swiss.alias

.include <bsd.port.mk>

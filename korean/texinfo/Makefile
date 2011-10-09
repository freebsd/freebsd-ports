# New ports collection makefile for:    texinfo
# Date created:         25 Sep 2000
# Whom:                 cjh
#
# $FreeBSD$
#

PORTNAME=	texinfo
PORTVERSION=	0.4.1
PORTREVISION=	10
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	${PORTNAME}-ko-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Korean enabled Texinfo formatter

DEPRECATED=	Depends on korean/hlatex, which is DEPRECATED
EXPIRATION_DATE=	2011-10-31

RUN_DEPENDS=	hbibtex:${PORTSDIR}/korean/hlatex

GNU_CONFIGURE=	YES
USE_GETTEXT=	yes
USE_GMAKE=	YES

# local variables.
TEXMF=		${PREFIX}/share/texmf

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/texinfo-ko.tex \
			${WRKSRC}/doc/texinfo-ko-HLaTeX.tex \
			${TEXMF}/tex/texinfo
	${INSTALL_PROGRAM} ${WRKSRC}/util/texindex \
			${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/makeinfo/makeinfo \
			${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/texinfo-ko
	${INSTALL_DATA} ${WRKSRC}/README.ko \
			${WRKSRC}/NEWS.ko \
			${WRKSRC}/TODO.ko \
			${PREFIX}/share/doc/texinfo-ko

post-install:
	${PREFIX}/bin/texhash

.include <bsd.port.mk>

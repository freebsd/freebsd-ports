# New ports collection makefile for:    texinfo
# Date created:         25 Sep 2000
# Whom:                 cjh
#
# $FreeBSD$
#

PORTNAME=	texinfo
PORTVERSION=	0.4.1
CATEGORIES=	korean print
MASTER_SITES=	http://master.debian.or.kr/~cwryu/archive/texinfo-ko/
DISTNAME=	${PORTNAME}-ko-${PORTVERSION}

MAINTAINER=	cjh@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	${LOCALBASE}/share/texmf/doc/latex/hlatex/uhc.ks:${PORTSDIR}/korean/hlatex

GNU_CONFIGURE=	YES
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

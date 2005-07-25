# New ports collection makefile for:	cwTeX Chinese TrueType fonts
# Date created:		18 Dec 2002
# Whom:			Shen Chuan-Hsing <satue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cwtexttf
PORTVERSION=	1.2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	ftp://ftp1.sinica.edu.tw/pub2/tex/cwTeX/cwTeX-TTF/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/cwTeX-TTF/
DISTNAME=	cwtex-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Five Chinese Big5 TrueType fonts made by cwTeX

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/texmf/fonts/truetype/cwTeX

TTF=		bbttf.ttf fttf.ttf kttf.ttf mttf.ttf rttf.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${FONTSDIR}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>

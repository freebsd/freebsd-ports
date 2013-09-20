# Created by: Shen Chuan-Hsing <satue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	cwtexttf
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://ftp.wustl.edu/pub/FreeBSD/distfiles/ \
		http://ftp.jaist.ac.jp/pub/FreeBSD/distfiles/
DISTNAME=	cwtex-ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Five Chinese Big5 TrueType fonts made by cwTeX

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/texmf/fonts/truetype/cwTeX

TTF=		bbttf.ttf fttf.ttf kttf.ttf mttf.ttf rttf.ttf

NO_STAGE=	yes
do-install:
	@${MKDIR} ${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${FONTSDIR}
.endfor

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>

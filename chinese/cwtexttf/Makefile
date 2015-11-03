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

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/texmf/fonts/truetype/cwTeX

TTF=		bbttf.ttf fttf.ttf kttf.ttf mttf.ttf rttf.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for i in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${FONTSDIR}
.endfor

.include "${.CURDIR}/../ttfm/Makefile.ttf"
.include <bsd.port.mk>

# New ports collection makefile for:	arne TrueType Font
# Date created:		10 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	arnettf
PORTVERSION=	0.0.20050501
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.linuxhall.org/download/fonts/:uming \
		http://debian.linux.org.tw/pub/3Anoppix/people/arne/ukai/:ukai
PKGNAMEPREFIX=	zh-
DISTFILES=	ttf-arphic-uming_0.1-0.dot.1.tar.gz:uming \
		ttf-arphic-ukai_0.0.20050501-1.tar.gz:ukai

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Arne TrueType Font is combine of arphic ming and kai fonts

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		ukai.ttf uming.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf-arphic-ukai-0.0.20050501/ukai.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf-arphic-uming-0.1/uming.ttf ${FONTSDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>

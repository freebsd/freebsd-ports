# New ports collection makefile for:	CJKUnifonts(Arne's TrueType Font)
# Date created:		10 Dec 2004
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	CJKUnifonts
PORTVERSION=	0.1.20060513
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/t/ttf-arphic-uming/:uming \
		http://ftp.debian.org/debian/pool/main/t/ttf-arphic-ukai/:ukai
PKGNAMEPREFIX=	zh-
DISTFILES=	ttf-arphic-uming_${PORTVERSION}.orig.tar.gz:uming \
		ttf-arphic-ukai_${PORTVERSION}.orig.tar.gz:ukai

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	CJKUnifonts TrueType Font is a combine of Arphic Ming and Kai fonts

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		ukai.ttf uming.ttf

do-install:
	@${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf-arphic-ukai-${PORTVERSION}/ukai.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf-arphic-uming-${PORTVERSION}/uming.ttf ${FONTSDIR}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>

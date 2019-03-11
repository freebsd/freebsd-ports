# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	hanyangfonts
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	korean x11-fonts
MASTER_SITES=	http://ftp.kaist.ac.kr/hangul/fonts/ \
		ftp://ftp.kaist.ac.kr/hangul/fonts/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	hanyang-font-pcf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hanyang Hangul fonts for X11

SUB_FILES=	pkg-message

USES=		fonts
NO_WRKSUBDIR=	yes
FONTNAME=	hanyang

FONTS=		hgm10 hgm12 hgm14 hgm16 hgm18 hgm20 \
		hmm10 hmm12 hmm14 hmm16 hmm18 hmm20

do-build:
	@cd ${WRKSRC}; \
	for fn in ${FONTS}; do \
		${GZIP_CMD} $$fn.pcf; \
		${ECHO} $$fn "compressed"; \
	done; \

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f}.pcf.gz \
		${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>

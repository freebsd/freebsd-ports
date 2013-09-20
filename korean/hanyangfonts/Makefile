# Created by: Junho CHOI <junho.choi@gmail.com>
# $FreeBSD$

PORTNAME=	hanyangfonts
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	korean x11-fonts
MASTER_SITES=	http://ftp.kaist.ac.kr/hangul/fonts/ \
		ftp://ftp.kaist.ac.kr/hangul/fonts/ \
		ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/
DISTNAME=	hanyang-font-pcf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hanyang Hangul fonts for X11

RUN_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

SUB_FILES=	pkg-message

NO_WRKSUBDIR=   yes

FONTS=		hgm10 hgm12 hgm14 hgm16 hgm18 hgm20 \
		hmm10 hmm12 hmm14 hmm16 hmm18 hmm20

NO_STAGE=	yes
do-build:
	@cd ${WRKSRC}; \
	for fn in ${FONTS}; do \
		${GZIP_CMD} $$fn.pcf; \
		${ECHO} $$fn "compressed"; \
	done; \

do-install:
	-${MKDIR} ${PREFIX}/lib/X11/fonts/local
	@cd ${WRKSRC}; \
	for f in ${FONTS}; do \
		${INSTALL_DATA} "$$f".pcf.gz ${PREFIX}/lib/X11/fonts/local; \
	done; \
	mkfontdir ${PREFIX}/lib/X11/fonts/local

.include <bsd.port.mk>

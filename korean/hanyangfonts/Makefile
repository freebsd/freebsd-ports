# New ports collection makefile for:    hanyangfonts
# Date created:         22 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanyangfonts
PORTVERSION=	1.0
CATEGORIES=	korean x11-fonts
MASTER_SITES=   ftp://ftp.kr.FreeBSD.org/pub/FreeBSD-kr/distfiles/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/
DISTNAME=	hanyang-font-pcf

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Hanyang Hangul fonts for X11

RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

NO_WRKSUBDIR=   yes

FONTS=		hgm10 hgm12 hgm14 hgm16 hgm18 hgm20 \
		hmm10 hmm12 hmm14 hmm16 hmm18 hmm20

do-build:
	@cd ${WRKSRC}; \
	for fn in ${FONTS}; do \
		${GZIP_CMD} $$fn.pcf; \
		${ECHO} $$fn "compressed"; \
	done; \

do-install:
	-${MKDIR} ${PREFIX}/lib/X11/fonts/local
	@cd ${WRKSRC}; \
	for file in ${FONTS}; do \
		${INSTALL_DATA} "$$file".pcf.gz ${PREFIX}/lib/X11/fonts/local; \
	done; \
	mkfontdir ${PREFIX}/lib/X11/fonts/local

.include <bsd.port.mk>

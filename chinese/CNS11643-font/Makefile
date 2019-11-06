# Created by: chinsan
# $FreeBSD$

PORTNAME=	CNS11643-font
PORTVERSION=	98.1
PORTREVISION=	6
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.cns11643.gov.tw/AIDB/file.do?path=download/%E5%AD%97%E5%9E%8B%E4%B8%8B%E8%BC%89%601q%60%E5%85%A8%E5%AD%97%E5%BA%AB%E6%AD%A3%E6%A5%B7%E9%AB%94/name/:kai \
		http://www.cns11643.gov.tw/AIDB/file.do?path=download/%E5%AD%97%E5%9E%8B%E4%B8%8B%E8%BC%89%601q%60%E5%85%A8%E5%AD%97%E5%BA%AB%E6%AD%A3%E5%AE%8B%E9%AB%94/name/:sung
DISTFILES=	TW-Kai-98_1.ttf:kai TW-Sung-98_1.ttf:sung
EXTRACT_ONLY=

MAINTAINER=	lhd@cs.nctu.edu.tw
COMMENT=	Combine of Kai and Sung with CNS11643 TrueType Fonts

BROKEN=		unfetchable

LICENSE=	CC_BY-ND_3.0_TW
LICENSE_NAME=	Creative Commons Attribution-NoDerivs 3.0 Taiwan License
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://creativecommons.org/licenses/by-nd/3.0/tw/
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TTF=		TW-Kai-98_1.ttf TW-Sung-98_1.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${TTF}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${STAGEDIR}${FONTSDIR}
.endfor

.include "${.CURDIR}/../ttfm/Makefile.ttf"
.include <bsd.port.mk>

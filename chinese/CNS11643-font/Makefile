PORTNAME=	CNS11643-font
PORTVERSION=	98.1
PORTREVISION=	6
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	https://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/CNS11643-font/
DISTFILES=	TW-Kai-98_1.ttf TW-Sung-98_1.ttf
EXTRACT_ONLY=

MAINTAINER=	lhd@cs.nctu.edu.tw
COMMENT=	Combine of Kai and Sung with CNS11643 TrueType Fonts

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

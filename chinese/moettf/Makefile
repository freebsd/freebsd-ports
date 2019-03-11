# Created by: Jing-Tang Keith Jang <keith@FreeBSD.org>
# $FreeBSD$

PORTNAME=	moettf
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	LOCAL/marino/zh-moettf
DISTFILES=	edustds1.exe edustds2.exe edustd-15.exe \
		kai-pc.ttf moe_kai.ttf moe_sung.ttf
DIST_SUBDIR=	zh-moettf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three Chinese BIG5 TrueType fonts: Kai LiShu Sung SungExt

EXTRACT_DEPENDS=	unrar:archivers/unrar

NO_CDROM=	Contact Ministry of Education of Taiwan for commercial use
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

TTF_DEFAULT=	moe_sung.ttf
TTF_DEFAULTKAI=	moe_kai.ttf
EXE_TTF=	moe_lishu.ttf moe_sungext.ttf moe_sungsym.ttf
REG_TTF=	kai-pc.ttf moe_kai.ttf moe_sung.ttf
TTF=		${EXE_TTF} ${REG_TTF}

do-extract:
	@${MKDIR} ${WRKSRC}
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustd-15.exe ${WRKSRC}
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustds1.exe ${WRKSRC}
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustds2.exe ${WRKSRC}
	@(cd ${WRKSRC}; \
		${MV} Edustd-15.TTF moe_lishu.ttf ; \
		${MV} edustds1.ttf moe_sungext.ttf ; \
		${MV} edustds2.ttf moe_sungsym.ttf )

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for ttf in ${EXE_TTF}
	${INSTALL_DATA} ${WRKSRC}/${ttf} ${STAGEDIR}${FONTSDIR}/${ttf}
.endfor
.for ttf in ${REG_TTF}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${ttf} \
		${STAGEDIR}${FONTSDIR}/${ttf}
.endfor

.include "${.CURDIR}/../ttfm/Makefile.ttf"
.include <bsd.port.mk>

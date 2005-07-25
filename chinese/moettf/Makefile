# New ports collection makefile for:	Chinese Big5 TrueType fonts
# Date created:		9 July 1999
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	moettf
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	http://www.edu.tw/download/mandr/biauword/5879/ \
		http://www.edu.tw/download/mandr/allbook/lishu/ \
		http://www.edu.tw/download/mandr/biauword/kai/ \
		ftp://freebsd.sinica.edu.tw/pub/keith/moettf/ \
		ftp://ftp.cc.ntut.edu.tw/OS/Linux/packages/chinese/fonts/twmoefont/ttf/
DISTFILES=	moe_kai.ttf moe_sung.ttf edustds1.exe edustds2.exe \
		edustd-15.exe kai-pc.ttf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Three Chinese BIG5 TrueType fonts: Kai LiShu Sung SungExt

EXTRACT_DEPENDS=unrar:${PORTSDIR}/archivers/unrar

DIST_SUBDIR=	zh-moettf

NO_CDROM=	"Contact Taiwan's Ministry of Education for commercial use."
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

TTF_DEFAULT=	moe_sung.ttf
TTF_DEFAULTKAI=	moe_kai.ttf
TTF=		moe_lishu.ttf moe_kai.ttf moe_sung.ttf moe_sungext.ttf moe_sungsym.ttf

do-extract:
	@${MKDIR} ${WRKSRC}
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustd-15.exe ${WRKSRC}
	@${MV} ${WRKSRC}/Edustd-15.TTF ${WRKSRC}/moe_lishu.ttf
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustds1.exe ${WRKSRC}
	@${MV} ${WRKSRC}/edustds1.ttf ${WRKSRC}/moe_sungext.ttf
	@unrar x ${DISTDIR}/${DIST_SUBDIR}/edustds2.exe ${WRKSRC}
	@${MV} ${WRKSRC}/edustds2.ttf ${WRKSRC}/moe_sungsym.ttf
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/moe_kai.ttf ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/moe_sung.ttf ${WRKSRC}

do-install:
	@${MKDIR} ${FONTSDIR}
.for ttf in ${TTF}
	${INSTALL_DATA} ${WRKSRC}/${ttf} ${FONTSDIR}
.endfor

post-install:
.if !defined(WITHOUT_X11)
.for f in fonts.dir fonts.alias
	${SED} -e "s/ t w m o e _ k a i/twmoe_kai/g" \
		-e "s/ ° ê ¦ r ¼ Ð · Ç § º Å é/twmoe_sung/g" \
		${XFONTSDIR}/${f} > ${XFONTSDIR}/${f}.$$ && \
		${MV} ${XFONTSDIR}/${f}.$$ ${XFONTSDIR}/${f}
.endfor
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/chinese/ttfm/Makefile.ttf"
.include <bsd.port.post.mk>

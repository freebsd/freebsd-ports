# New ports collection makefile for:	zh-Big5/GB-ized ghostscript6
# Date created:		Nov 27 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ghostscript
PORTVERSION=	6.50
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/CID/CMap/ \
		ftp://freebsd.sinica.edu.tw/pub/keith/GS6TTF/ \
		ftp://ftp.oreilly.com/pub/examples/nutshell/cjkv/adobe/ \
		http://www.aihara.co.jp/~taiji/tops/
DISTFILES=	ac13.tar.Z ag13.tar.Z ai0.tar.Z aj14.tar.Z \
		aj20.tar.Z ak12.tar.Z rksj-cmaps.tar.Z \
		cjkvttcidmap-0.8.tar.gz gs6.50_ttf.ps-cjkv-20001215.patch.gz
EXTRACT_ONLY=

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/6.50/lib/gs_ttf.ps:${PORTSDIR}/print/ghostscript6 \
		ttfm.sh:${PORTSDIR}/chinese/ttfm

NO_BUILD=	yes
PLIST_SUB=	GS_VERSION=${PORTVERSION}

do-install:
	@${MKDIR} ${PREFIX}/share/ghostscript/CJK/CIDFont
	@${MKDIR} ${PREFIX}/share/ghostscript/CJK/CMap
	@${MKDIR} ${PREFIX}/share/ghostscript/CJK/Font
	@${MKDIR} ${PREFIX}/share/ghostscript/CJK/TrueType
.for f in ac13 ag13 ak12 ai0 aj14 aj20
	@(cd ${PREFIX}/share/ghostscript/CJK/CMap; \
		${TAR} -xzf ${DISTDIR}/$f.tar.Z; \
		${LN} -sf $f/CMap/* . )
.endfor
	@(cd ${PREFIX}/share/ghostscript/CJK/CMap; \
		${TAR} -xzf ${DISTDIR}/rksj-cmaps.tar.Z; \
		${LN} -sf rksj-cmaps/* . )
	@(cd ${PREFIX}/share/ghostscript/CJK/TrueType; \
		${TAR} -xzf ${DISTDIR}/cjkvttcidmap-0.8.tar.gz )
	@(cd ${PREFIX}/share/ghostscript/6.50/lib; \
		${GZCAT} ${DISTDIR}/gs6.50_ttf.ps-cjkv-20001215.patch.gz |${PATCH} )
	@${CP} ${PREFIX}/share/ghostscript/6.50/lib/gs_res.ps \
		${PREFIX}/share/ghostscript/6.50/lib/gs_res.ps.orig
	@${SED} -e "s:(/Resource/):(${PREFIX}/share/ghostscript/CJK/):g" \
		-e "s:(/Resource/Font/):(${PREFIX}/share/ghostscript/CJK/Font/):g" \
		${PREFIX}/share/ghostscript/6.50/lib/gs_res.ps.orig > \
		${PREFIX}/share/ghostscript/6.50/lib/gs_res.ps

.include	<bsd.port.mk>

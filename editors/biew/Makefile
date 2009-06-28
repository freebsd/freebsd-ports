# New ports collection makefile for:	biew
# Date created:				04 February 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	biew
PORTVERSION=	5.7.3.1
CATEGORIES=	editors
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary file viewer and editor

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --with-extraincdir="${LOCALBASE}/include" \
		--ld="${CC}" --with-extralibdir="${LOCALBASE}/lib" \
		--prefix="${PREFIX}" --datadir="${DATADIR}"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/biew \
		%%DATADIR%%/assembly.skn \
		%%DATADIR%%/biew.hlp \
		%%DATADIR%%/golded.skn \
		%%DATADIR%%/insight.skn \
		%%DATADIR%%/standard.skn
PLIST_DIRS=	%%DATADIR%%

MAN1=		biew.1
PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru licence.en licence.ru release.txt unix.txt

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' ${WRKSRC}/configure

post-build:
	${LN} -sf ../../biewlib ${WRKSRC}/tools/biewhlp/biewlib
	cd ${WRKSRC}/tools/biewhlp && ${GMAKE} ${MAKE_ARGS}
	${LN} -sf ../../biewlib ${WRKSRC}/tools/lzss/biewlib
	cd ${WRKSRC}/tools/lzss && ${GMAKE} ${MAKE_ARGS}
	(cd ${WRKSRC}/hlp; ${LN} -sf ../tools/biewhlp/biewhlp; \
	${LN} -sf ../tools/lzss/lzss; ./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/*.skn ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hlp/biew.hlp ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/biew.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

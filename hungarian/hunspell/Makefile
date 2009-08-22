# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.2.8
CATEGORIES=	hungarian textproc
MASTER_SITES=	SF/${PORTNAME}/Hunspell/${PORTVERSION}:code \
		SF/magyarispell/Magyar%20Ispell/${DICTVERSION}:data
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:code	\
		hu_HU-${DICTVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Improved spell-checker for Hungarian and other languages

#EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ui --with-libintl-prefix=${PREFIX} --with-readline
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include LDFLAGS=-L${PREFIX}/lib
EXTRACT_AFTER_ARGS=|${TAR} -xpf - --exclude intl
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

MAN1=		hunspell.1
MAN4=		hunspell.4

DICTVERSION=	1.4
PORTDOCS=	README README.myspell

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/tools/hunspell.cxx

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.4 ${PREFIX}/man/man4
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/.libs/hunspell ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/hunspell
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/*.h* ${PREFIX}/include/hunspell/
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/.libs/libhunspell-1.2.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/.libs/libhunspell-1.2.lai ${PREFIX}/lib/libhunspell-1.1.la
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/.libs/libhunspell-1.2.so.0 ${PREFIX}/lib
	${LN} -s ${LOCALBASE}/lib/libhunspell-1.2.so.0 ${PREFIX}/lib/libhunspell-1.2.so
	${MKDIR} ${PREFIX}/share/myspell/
	${INSTALL_DATA} ${WRKDIR}/hu_HU-${DICTVERSION}/hu_HU.dic \
		${WRKDIR}/hu_HU-${DICTVERSION}/hu_HU.aff \
		${PREFIX}/share/myspell/
	${INSTALL_DATA} ${WRKSRC}/hunspell.pc ${PREFIX}/libdata/pkgconfig/
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/magyar.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/hungarian.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.dic ${PREFIX}/share/myspell/default.dic
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/magyar.aff
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/hungarian.aff
	${LN} -s ${LOCALBASE}/share/myspell/hu_HU.aff ${PREFIX}/share/myspell/default.aff
	#${LOCALBASE}/bin/msgfmt -o ${WRKSRC}/hunspell.mo ${WRKSRC}/hunspell.po
	#${MKDIR} ${PREFIX}/share/locale/hu/LC_MESSAGES/ && \
	#${INSTALL_DATA} ${WRKSRC}/hunspell.mo ${PREFIX}/share/locale/hu/LC_MESSAGES/

.ifndef(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

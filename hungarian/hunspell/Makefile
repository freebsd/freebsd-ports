# New ports collection makefile for:    hunspell
# Date created:         24.07.2004
# Whom:                 janos.mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.2.2b
CATEGORIES=	hungarian textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S@$@:code@:S@%SUBDIR%@${PORTNAME}@} \
		${MASTER_SITE_SOURCEFORGE:S@$@:data@:S@%SUBDIR%@magyarispell@}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:code hu_HU-${DICTVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Improved Hungarian spelling checker

#EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-ui"

MAN1=		hunspell.1
MAN4=		hunspell.4

DICTVERSION=	1.3
PORTDOCS=	README README.myspell

.include <bsd.port.pre.mk>

# Ugly workaround for FreeBSD versions before the import of NetBSD gzip.
#do-extract:
#	@${RM} -rf ${WRKDIR}; \
#	${MKDIR} ${WRKDIR}; \
# 	cd ${WRKDIR} && ${TAR} -xzf  ${_DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX};\
#		${UNZIP_CMD} -qo ${_DISTDIR}/hu_HU.zip -d ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/tools/hunspell.cxx

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/hunspell.4 ${PREFIX}/man/man4
	${INSTALL_PROGRAM} ${WRKSRC}/src/tools/.libs/hunspell ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/.libs/libhunspell-1.2.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/.libs/libhunspell-1.2.lai ${PREFIX}/lib/libhunspell-1.1.la
	${INSTALL_DATA} ${WRKSRC}/src/hunspell/.libs/libhunspell-1.2.so.0 ${PREFIX}/lib
	${LN} -s ${LOCALBASE}/lib/libhunspell-1.2.so.0 ${PREFIX}/lib/libhunspell-1.2.so
	${MKDIR} ${PREFIX}/share/myspell/ && \
	${INSTALL_DATA} ${WRKDIR}/hu_HU-${DICTVERSION}/hu_HU.dic \
	${PREFIX}/share/myspell/ && \
	${INSTALL_DATA} ${WRKDIR}/hu_HU-${DICTVERSION}/hu_HU.aff \
	${PREFIX}/share/myspell/
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

# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waeijiro-fpw
PORTVERSION=	1.1
PORTREVISION=	6
CATEGORIES=	japanese
#MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/
MASTER_SITES=	http://www.dsl.gr.jp/~tf/pool/
#DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAEIJIRO English - Japanese Dictionary (EPWING V1 format)

EXTRACT_DEPENDS=${LOCALBASE}/share/freepwing/fpwutils.mk:japanese/freepwing \
		lha:archivers/lha
BUILD_DEPENDS=	${LOCALBASE}/libexec/freepwing/catdump:japanese/freepwing \
		ja-p5-Jcode>=0:japanese/p5-Jcode

MANUAL_PACKAGE_BUILD=Needs data from a CDROM
MAKE_JOBS_UNSAFE=	yes

RESTRICTED=	The original dictionary is not free
USES=		perl5 gmake
PORTDOCS=	README
DICT_PATH?=	/cdrom
SRCFILE?=	waeiji52.txt

PLIST_FILES=	share/dict/waeijiro-fpw/waeijiro/data/honmon \
		share/dict/waeijiro-fpw/catalogs

# For eijiro included in a book sold by ALC Inc.
# (http://www.alc.co.jp/alcshop/eng/eijiro/)

.if exists(${DICT_PATH}/${SRCFILE})
SOURCE_FILE=	${DICT_PATH}/${SRCFILE}
.else
SOURCE_FILE=	${WRKDIR}/${SRCFILE}
.endif
MAKE_ARGS+=	SRC_DICT=${SOURCE_FILE:Q}

OPTIONS_DEFINE= DOCS

.include <bsd.port.options.mk>

post-extract:
	@if [ -f ${DICT_PATH}/eijiro-original/*.exe ]; then \
	  lha xiw=${WRKDIR} ${DICT_PATH}/eijiro-original/*.exe '*/${SRCFILE}'; \
	fi
	@if [ ! -f ${SOURCE_FILE:Q} ]; then \
	  ${ECHO} "###################################################"; \
	  ${ECHO} "I cannot find a file ${DICT_PATH}/${SRCFILE}"; \
	  ${ECHO} "Specify the Waeijiro Dictionary file with the full path"; \
	  ${ECHO} "and excecute the following command again:"; \
	  ${ECHO} "  make DICT_PATH=${DICT_PATH} SRCFILE=${SRCFILE}"; \
	  ${ECHO} ""; \
	  ${ECHO} "Notice: DICT_PATH must be a full path to the file."; \
	  ${ECHO} "###################################################"; \
	  ${FALSE}; \
	fi
	${CP} ${LOCALBASE}/share/freepwing/fpwutils.mk ${WRKSRC}

post-build:
	cd ${WRKSRC}; fpwmake catalogs

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/waeijiro-fpw/waeijiro/data \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/honmon \
		${STAGEDIR}${PREFIX}/share/dict/waeijiro-fpw/waeijiro/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/waeijiro-fpw
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

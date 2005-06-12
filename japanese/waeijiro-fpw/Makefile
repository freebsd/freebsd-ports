# New ports collection makefile for:	WAEIJIRO Dictionary - JIS X 4081 version
# Date created:        	2002.9.9
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	waeijiro-fpw
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	japanese
#MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/
MASTER_SITES=	http://www.dsl.gr.jp/~tf/pool/
#DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WAEIJIRO English - Japanese Dictionary (EPWING V1 format)

EXTRACT_DEPENDS=${LOCALBASE}/share/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing
BUILD_DEPENDS=	${LOCALBASE}/libexec/freepwing/catdump:${PORTSDIR}/japanese/freepwing \
		${SITE_PERL}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode

RESTRICTED=	"The original dictionary is not free"
NO_PACKAGE=	"The original dictionary is not free"
USE_GMAKE=	yes
DICT_PATH?=	/cdrom
SRCFILE?=	waeiji52.txt

# For eijiro included in a book sold by ALC Inc.
# (http://www.alc.co.jp/alcshop/eng/eijiro/)
.include <bsd.port.pre.mk>
DICT_ARCHIVE!=	${ECHO_CMD} ${DICT_PATH}/eijiro-original/*.exe || ${TRUE}
.if exists(${DICT_ARCHIVE})
EXTRACT_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

CDROM_PATH:=	${DICT_PATH}
DICT_PATH:=	${WRKDIR}
.else
CDROM_PATH=	${NONEXISTENT}
.endif

MAKE_ARGS:=	SRC_DICT=${DICT_PATH}/${SRCFILE}

post-extract:
	@if [ -f ${CDROM_PATH}/eijiro-original/*.exe ]; then \
	  lha xiw=${WRKDIR} ${CDROM_PATH}/eijiro-original/*.exe '*/${SRCFILE}'; \
	elif [ ! -f ${DICT_PATH}/${SRCFILE} ]; then \
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
	${MKDIR} ${PREFIX}/share/dict/waeijiro-fpw/waeijiro/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/waeijiro-fpw/waeijiro/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/waeijiro-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

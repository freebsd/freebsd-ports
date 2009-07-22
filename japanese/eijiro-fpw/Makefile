# New ports collection makefile for:	EIJIRO Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eijiro-fpw
PORTVERSION=	1.0b
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EIJIRO English - Japanese Dictionary (EPWING V1 format)

EXTRACT_DEPENDS=${LOCALBASE}/share/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing
BUILD_DEPENDS=	${LOCALBASE}/libexec/freepwing/catdump:${PORTSDIR}/japanese/freepwing \
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode

MANUAL_PACKAGE_BUILD=Needs data from CDROM
RESTRICTED=	"The original dictionary is not free"
USE_GMAKE=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/eijiro-fpw${PORTVERSION}
DICT_PATH?=	/cdrom
SRCFILE?=	eijiro52.txt

# For eijiro included in a book sold by ALC Inc.
# (http://www.alc.co.jp/alcshop/eng/eijiro/)

JCODE=	${SITE_PERL}/Jcode.pm

.include <bsd.port.pre.mk>

DICT_ARCHIVE!=	${ECHO_CMD} ${DICT_PATH}/eijiro-original/*.exe || ${TRUE}
.if exists(${DICT_ARCHIVE})
EXTRACT_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

CDROM_PATH:=	${DICT_PATH}
DICT_PATH:=	${WRKDIR}
.else
CDROM_PATH=	${NONEXISTENT}
.endif

MAKE_ARGS:=	SRCFILE=${DICT_PATH}/${SRCFILE}

post-extract:
	@if [ -f ${CDROM_PATH}/eijiro-original/*.exe ]; then \
	  lha xiw=${WRKDIR} ${CDROM_PATH}/eijiro-original/*.exe '*/${SRCFILE}'; \
	elif [ ! -f ${DICT_PATH}/${SRCFILE} ]; then \
	  ${ECHO} "###################################################"; \
	  ${ECHO} "I cannot find a file ${DICT_PATH}/${SRCFILE}"; \
	  ${ECHO} "Specify the Eijiro Dictionary file with the full path"; \
	  ${ECHO} "and excecute the following command again:"; \
	  ${ECHO} "  make DICT_PATH=${DICT_PATH} SRCFILE=${SRCFILE}"; \
	  ${ECHO} ""; \
	  ${ECHO} "Notice: DICT_PATH must be a full path to the file."; \
	  ${ECHO} "###################################################"; \
	  ${FALSE}; \
	fi
	${CP} ${LOCALBASE}/share/freepwing/fpwutils.mk ${WRKSRC}

post-build:
	cd ${WRKSRC}; ${CP} catalogs.sjis catalogs.txt; \
	${SETENV} CATDUMPFLAGS="-e sjis" fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/eijiro-fpw/eijiro/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/eijiro-fpw/eijiro/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/eijiro-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.sjis
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

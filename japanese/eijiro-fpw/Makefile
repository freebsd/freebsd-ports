# New ports collection makefile for:	EIJIRO Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eijiro-fpw
PORTVERSION=	1.0b
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	EIJIRO English - Japanese Dictionary (EPWING V1 format)

EXTRACT_DEPENDS=${LOCALBASE}/share/doc/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing
BUILD_DEPENDS=	${LOCALBASE}/libexec/freepwing/catdump:${PORTSDIR}/japanese/freepwing \
		${SITE_PERL}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode

RESTRICTED=	"The original dictionary is not free"
NO_PACKAGE=	"The original dictionary is not free"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/eijiro-fpw${PORTVERSION}
DICT_PATH?=	/cdrom
SRCFILE?=	eijiro52.txt

# For eijiro included in a book sold by ALC Inc.
# (http://www.alc.co.jp/alcshop/eng/eijiro/)
.if exists(${DICT_PATH}/eijiro-original)
BUILD_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

CDROM_PATH:=	${DICT_PATH}
DICT_PATH:=	${WRKDIR}
.else
CDROM_PATH=	${NONEXISTENT}
.endif

MAKE_ARGS:=	PORT_SRCFILE=${DICT_PATH}/${SRCFILE}

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
	${CP} ${LOCALBASE}/share/doc/freepwing/fpwutils.mk ${WRKSRC}

post-build:
	cd ${WRKSRC}; ${CP} catalogs.sjis catalogs.txt; \
	${SETENV} CATDUMPFLAGS="-e sjis" fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/eijiro-fpw/eijiro/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/eijiro-fpw/eijiro/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/eijiro-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/eijiro-fpw
.for i in readme.sjis
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/eijiro-fpw
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	OTOJIRO Dictionary - JIS X 4081 version
# Date created:        	2002.9.9
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	otojiro-fpw
PORTVERSION=	1.0.a
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/ \
		http://member.nifty.ne.jp/~satomii/freepwing/archive/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.a/a/}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OTOJIRO English - Japanese Dictionary (EPWING V1 format)

EXTRACT_DEPENDS=${LOCALBASE}/share/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing
BUILD_DEPENDS=	${LOCALBASE}/libexec/freepwing/catdump:${PORTSDIR}/japanese/freepwing \
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode

RESTRICTED=	"The original dictionary is not free"
NO_PACKAGE=	"The original dictionary is not free"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/otojiro-fpw${PORTVERSION:S/.a/a/}
DICT_PATH?=	/cdrom
SRCFILE?=	otojiro.txt

# For eijiro included in a book sold by ALC Inc.
# (http://www.alc.co.jp/alcshop/eng/eijiro/)
.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500801
JCODE=	${SITE_PERL}/${PERL_ARCH}/Jcode.pm
.else
JCODE=	${SITE_PERL}/Jcode.pm
.endif

DICT_ARCHIVE!=	${ECHO_CMD} ${DICT_PATH}/eijiro-original/*.exe || ${TRUE}
.if exists(${DICT_ARCHIVE})
EXTRACT_DEPENDS+=	lha:${PORTSDIR}/archivers/lha

CDROM_PATH:=	${DICT_PATH}
DICT_PATH:=	${WRKDIR}
.else
CDROM_PATH=	${NONEXISTENT}
.endif

MAKE_ENV:=	OTOJIRO_FILE=${DICT_PATH}/${SRCFILE}

post-extract:
	@if [ -f ${CDROM_PATH}/eijiro-original/*.exe ]; then \
	  ${MKDIR} ${WRKDIR}; \
	  lha xiw=${WRKDIR} ${CDROM_PATH}/eijiro-original/*.exe '*/${SRCFILE}'; \
	elif [ ! -f ${DICT_PATH}/${SRCFILE} ]; then \
	  ${ECHO} "###################################################"; \
	  ${ECHO} "I cannot find a file ${DICT_PATH}/${SRCFILE}"; \
	  ${ECHO} "Specify the Otojiro Dictionary file with the full path"; \
	  ${ECHO} "and excecute the following command again:"; \
	  ${ECHO} "  make DICT_PATH=${DICT_PATH} SRCFILE=${SRCFILE}"; \
	  ${ECHO} ""; \
	  ${ECHO} "Notice: DICT_PATH must be a full path to the file."; \
	  ${ECHO} "###################################################"; \
	  ${FALSE}; \
	fi

post-patch:
	@${REINPLACE_CMD} -e "s/FPWPARSERFLAGS = -- /FPWPARSERFLAGS = /g" ${WRKSRC}/Makefile

do-build:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} fpwmake; \
	fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/otojiro-fpw/otojiro/data
	${MKDIR} ${PREFIX}/share/dict/otojiro-fpw/otojiro/gaiji
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/otojiro-fpw/otojiro/data
#	${INSTALL_DATA} ${WRKSRC}/gai16f \
#		${PREFIX}/share/dict/otojiro-fpw/otojiro/gaiji
	${INSTALL_DATA} ${WRKSRC}/gai16h \
		${PREFIX}/share/dict/otojiro-fpw/otojiro/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/otojiro-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.txt COPYING
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

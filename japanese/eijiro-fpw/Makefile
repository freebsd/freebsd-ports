# New ports collection makefile for:	EIJIRO Dictionary - JIS X 4081 version
# Date created:        	2000.11.28
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eijiro-fpw
PORTVERSION=	1.0b
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/doc/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil \
		nkf:${PORTSDIR}/japanese/nkf \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode

RESTRICTED=	"The original dictionary is not free"
NO_PACKAGE=	"The original dictionary is not free"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/eijiro-fpw${PORTVERSION}
DICT_PATH?=	/cdrom
SRCFILE?=	EIJI37??.TXT
MAKE_ENV=	PORT_SRCFILE=${DICT_PATH}/${SRCFILE}

post-extract:
	@if [ ! -f ${DICT_PATH}/${SRCFILE} ]; then \
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
	cd ${WRKSRC}; nkf -eSd catalogs.sjis > catalogs.txt; \
	catdump -u catalogs.txt catalogs

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

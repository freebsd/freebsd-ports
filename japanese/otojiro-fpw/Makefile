# New ports collection makefile for:	OTOJIRO Dictionary - JIS X 4081 version
# Date created:        	2002.9.9
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	otojiro-fpw
PORTVERSION=	1.0.a
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/eijiro/ \
		http://member.nifty.ne.jp/~satomii/freepwing/archive/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.a/a/}-src

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/doc/freepwing/fpwutils.mk:${PORTSDIR}/japanese/freepwing \
		nkf:${PORTSDIR}/japanese/nkf \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode

RESTRICTED=	"The original dictionary is not free"
NO_PACKAGE=	"The original dictionary is not free"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/otojiro-fpw${PORTVERSION:S/.a/a/}
DICT_PATH?=	/cdrom
SRCFILE?=	otojiro.txt
MAKE_ENV=	OTOJIRO_FILE=${DICT_PATH}/${SRCFILE}

pre-extract::
	@if [ ! -f ${DICT_PATH}/${SRCFILE} ]; then \
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

post-build:
## To delete CR after NL
	cd ${WRKSRC}; ${MV} catalogs.txt catalogs.txt.org; \
	nkf -sSd catalogs.txt.org > catalogs.txt; \
	fpwmake catalogs

do-build:
	cd ${WRKSRC}; ${ENV} ${MAKE_ENV} fpwmake

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
	${MKDIR} ${PREFIX}/share/doc/otojiro-fpw
.for i in readme.txt COPYING
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/otojiro-fpw
.endfor
.endif

.include <bsd.port.mk>

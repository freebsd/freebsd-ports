# New ports collection makefile for:	mypaedia - JIS X 4081 format version
# Date created:        	00/02/21
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mypaedia-fpw
PORTVERSION=	1.4.3
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/mypaedia/
DISTNAME=	mypaedia-fpw${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An encyclopedia  "Mypaedia" (EPWING V1 format)

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode

IS_INTERACTIVE= YES
RESTRICTED=	"The original dictionary is not free"
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/mypaedia-fpw${PORTVERSION}
DICT_PATH?=	/cdrom

post-extract:
	@if [ ! -f ${DICT_PATH}/INDEX/ITEM.DAT ]; then \
	  ${ECHO} "###################################################"; \
	  ${ECHO} "Specify a mount point for Mypaedia's CD-ROM"; \
	  ${ECHO} "and excecute the following command again:"; \
	  ${ECHO} "  make DICT_PATH=${DICT_PATH}"; \
	  ${ECHO} "###################################################"; \
	  ${FALSE}; \
	fi

do-build:
#	cd ${WRKSRC}; fpwmake SRCDIR=${DICT_PATH} > /dev/null; \
	cd ${WRKSRC}; fpwmake SRCDIR=${DICT_PATH}; \
	fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/mypaedia-fpw/mypaedia/data
	${MKDIR} ${PREFIX}/share/dict/mypaedia-fpw/mypaedia/gaiji
	${INSTALL_DATA} ${WRKSRC}/honmon \
		${PREFIX}/share/dict/mypaedia-fpw/mypaedia/data
	${INSTALL_DATA} ${WRKSRC}/gai16f \
		${PREFIX}/share/dict/mypaedia-fpw/mypaedia/gaiji
	${INSTALL_DATA} ${WRKSRC}/gai16h \
		${PREFIX}/share/dict/mypaedia-fpw/mypaedia/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/mypaedia-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog GAIJI.TXT MYPAEDIA-format.txt README.PKG README.TXT TOBEDONE
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

JCODE=	${SITE_PERL}/Jcode.pm

.include <bsd.port.mk>

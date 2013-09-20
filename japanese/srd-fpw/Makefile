# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	srd-fpw
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/srd/
DISTNAME=	srd-fpw${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A English - Japanese Dictionary "Random House" (EPWING V1 format)

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		ja-p5-Jcode>=0:${PORTSDIR}/japanese/p5-Jcode

IS_INTERACTIVE= YES
RESTRICTED=	The original dictionary is not free
USES=		perl5
WRKSRC=		${WRKDIR}/srd-fpw${PORTVERSION}
DICT_PATH?=	/cdrom

NO_STAGE=	yes
post-extract:
	@if [ ! -f ${DICT_PATH}/SRD.INI ]; then \
	  ${ECHO} "###################################################"; \
	  ${ECHO} "Specify a mount point for Random House's CD-ROM"; \
	  ${ECHO} "or a directory which you copied it from the CD-ROM".; \
	  ${ECHO} "And excecute the following command again:"; \
	  ${ECHO} "  make DICT_PATH=${DICT_PATH}"; \
	  ${ECHO} "###################################################"; \
	  ${FALSE}; \
	fi

do-build:
#	cd ${WRKSRC}; fpwmake SRCDIR=${DICT_PATH} > /dev/null; \
	cd ${WRKSRC}; \
	fpwmake SRCDIR=${DICT_PATH} png; \
	fpwmake SRCDIR=${DICT_PATH}; \
	fpwmake catalogs

do-install:
	${MKDIR} ${PREFIX}/share/dict/srd-fpw/srd-fpw/data
	${MKDIR} ${PREFIX}/share/dict/srd-fpw/srd-fpw/gaiji
	${INSTALL_DATA} ${WRKSRC}/honmon \
		${PREFIX}/share/dict/srd-fpw/srd-fpw/data
	${INSTALL_DATA} ${WRKSRC}/gai16f \
		${PREFIX}/share/dict/srd-fpw/srd-fpw/gaiji
	${INSTALL_DATA} ${WRKSRC}/gai16h \
		${PREFIX}/share/dict/srd-fpw/srd-fpw/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/srd-fpw
	${INSTALL_DATA} ${WRKSRC}/img.dat ${PREFIX}/share/dict/srd-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in AUTHORS COPYING ChangeLog GAIJI.TXT NEWS README.PKG README.TXT TOBEDONE
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	mypaedia - JIS X 4081 format version
# Date created:        	00/02/21
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mypaedia-fpw
PORTVERSION=	1.4
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/mypaedia-fpw/
DISTNAME=	mypaedia-fpw${PORTVERSION}-src

MAINTAINER=    	taoka@FreeBSD.org

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Jcode.pm:${PORTSDIR}/japanese/p5-Jcode

IS_INTERACTIVE= YES
RESTRICTED=	"The original dictionary is not free"
WRKSRC=		${WRKDIR}/mypaedia-fpw${PORTVERSION}
MOUNT_PT?=	/cdrom

post-extract:
	@if [ ! -f ${MOUNT_PT}/INDEX/ITEM.DAT ]; then \
	  ${ECHO} "###################################################"; \
	  ${ECHO} "Specify a mount point for Mypaedia's CD-ROM"; \
	  ${ECHO} "and excecute the following command again:"; \
	  ${ECHO} "  make MOUNT_PT=${MOUNT_PT}"; \
	  ${ECHO} "###################################################"; \
	  ${FALSE}; \
	fi

do-build:
#	cd ${WRKSRC}; fpwmake SRCDIR=${MOUNT_PT} > /dev/null; \
	cd ${WRKSRC}; fpwmake SRCDIR=${MOUNT_PT}; \
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
	${MKDIR} ${PREFIX}/share/doc/mypaedia-fpw
.for file in README.TXT README.PKG AUTHORS COPYING ChangeLog GAIJI.TXT TOBEDONE NEWS
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mypaedia-fpw
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	fte
# Date created:				8 May 2000
# Whom:					gelf
#
# $FreeBSD$
#

PORTNAME=		fte
PORTVERSION=		46.5
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}s${PORTVERSION:S/./b/}
EXTRACT_SUFX=		.zip

MAINTAINER=		mail@gelf.com

BUILD_DEPENDS=  	unzip:${PORTSDIR}/archivers/unzip

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=
USE_NEWGCC=		yes

.include "${.CURDIR}/files/conffiles"

do-build:
	(cd ${WRKSRC}/src ; ${MAKE} -f fte-unix.mak)
	(cd ${WRKSRC}/config ; ../src/cfte main.fte)

do-install:
	${MKDIR} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/etc/fte
	${MKDIR} ${PREFIX}/lib/fte/etc/kbd
	${MKDIR} ${PREFIX}/lib/fte/etc/menu

	${INSTALL_PROGRAM} ${WRKSRC}/src/xfte ${PREFIX}/bin/fte
	${INSTALL_DATA} ${WRKSRC}/config/fte-new.cnf ${PREFIX}/etc/fte/system.fterc
.for CONFFILE in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/config/${CONFFILE} ${PREFIX}/lib/fte/etc
.endfor
.for KBDFILE in ${KBDFILES}
	${INSTALL_DATA} ${WRKSRC}/config/kbd/${KBDFILE} ${PREFIX}/lib/fte/etc/kbd
.endfor
	${INSTALL_DATA} ${WRKSRC}/config/menu/m_c.fte ${PREFIX}/lib/fte/etc/menu
	${INSTALL_DATA} ${WRKSRC}/config/menu/m_html.fte ${PREFIX}/lib/fte/etc/menu

.include <bsd.port.mk>

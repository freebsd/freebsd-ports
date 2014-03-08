# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	rasmol
PORTVERSION=	2.7.2.1.1
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.bernstein-plus-sons.com/software/
DISTNAME=	RasMol_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Molecular Visualization Program

WRKSRC=		${WRKDIR}/RasMol_${PORTVERSION}/src

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=		imake
USE_XORG=	x11 xext xi
MANCOMPRESSED=	no
XFREE86_HTML_MAN=	no

MAN1=		rasmol.1

PLIST_FILES=	bin/rasmol bin/rasmol-16 bin/rasmol-32 bin/rasmol-8 \
		lib/X11/rasmol/1crn.pdb lib/X11/rasmol/3cro.pdb \
		lib/X11/rasmol/rasmol.hlp
PLIST_DIRS=	lib/X11/rasmol

NO_STAGE=	yes
do-build:
	${SETENV} ${MAKE_ENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build_viewer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rasmol-* ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/rasmol ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rasmol.man ${MANPREFIX}/man/man1/rasmol.1
	${MKDIR} ${PREFIX}/lib/X11/rasmol
	${INSTALL_DATA} ${WRKSRC}/rasmol.hlp ${PREFIX}/lib/X11/rasmol
	${INSTALL_DATA} ${WRKSRC}/../data/1crn.pdb ${PREFIX}/lib/X11/rasmol
	${INSTALL_DATA} ${WRKSRC}/../data/3cro.pdb ${PREFIX}/lib/X11/rasmol

.include <bsd.port.mk>

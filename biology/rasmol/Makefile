# New ports collection Makefile for: rasmol
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	rasmol
PORTVERSION=	2.7.2
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.bernstein-plus-sons.com/software/RasMol_2.7.2/
DISTNAME=	RasMol

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Fast Molecular Visualization Program

WRKSRC=		${WRKDIR}/RasMol_2.7.2/src

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake
.elif ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	imake:${PORTSDIR}/devel/imake-4
.endif

MAN1=		rasmol.1

do-build:
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/build_viewer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rasmol-* ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/rasmol ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rasmol.man ${PREFIX}/man/man1/rasmol.1
	${MKDIR} ${PREFIX}/lib/X11/rasmol
	${INSTALL_DATA} ${WRKSRC}/rasmol.hlp ${PREFIX}/lib/X11/rasmol
	${INSTALL_DATA} ${WRKSRC}/../data/1crn.pdb ${PREFIX}/lib/X11/rasmol
	${INSTALL_DATA} ${WRKSRC}/../data/3cro.pdb ${PREFIX}/lib/X11/rasmol

.include <bsd.port.post.mk>

# New ports collection makefile for:   vgba-bin
# Date created:		04 Aug 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	vgba
PORTVERSION=	2.0
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/VGBA/
PKGNAMESUFFIX=	-bin
DISTNAME=	VGBA${PORTVERSION:S/.//}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Virtual GameBoy Advance is an emulator of Nintendo GameBoy Advance(TM)

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_SIZE=	yes
NO_BUILD=	no
NO_WRKSUBDIR=	no

INSTALL_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vgba ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/VGBA.html ${DOCSDIR}
.endif # !defined(NOPORTDOCS)

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

.include <bsd.port.post.mk>


# New ports collection makefile for:   vgba-bin
# Date created:		04 Aug 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	vgba
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/VGBA/
PKGNAMESUFFIX=	-bin
DISTNAME=	VGBA${PORTVERSION:S/.//}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Virtual GameBoy Advance is an emulator of Nintendo GameBoy Advance(TM)

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

ONLY_FOR_ARCHS=	i386
NO_BUILD=	no
NO_WRKSUBDIR=	no

INSTALL_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vgba ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/VGBA.html ${DOCSDIR}
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>

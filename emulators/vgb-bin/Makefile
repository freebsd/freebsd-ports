# New ports collection makefile for:   vgb-bin
# Date created:		04 Aug 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	vgb
PORTVERSION=	17
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/fms/VGB/
PKGNAMESUFFIX= -bin
DISTNAME=	VGB${PORTVERSION}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	lioux@FreeBSD.org

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
NO_BUILD=	no
WRKSRC=		${WRKDIR}/GB

INSTALL_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP}

.if defined(NOPORTDOCS)
PLIST_SUB+=     PORTDOCS:="@comment "
.else
PLIST_SUB+=     PORTDOCS:=
.endif # !defined(NOPORTDOCS)

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vgb ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/vgb-debug ${PREFIX}/bin
	@${INSTALL_DIR} ${PREFIX}/share/vgb
	@${INSTALL_DATA} ${WRKSRC}/CART.GB ${PREFIX}/share/vgb
.if !defined(NOPORTDOCS)
	${INSTALL_DIR} ${PREFIX}/share/doc/vgb ${PREFIX}/share/doc/vgb/demos
	@${INSTALL_DATA} ${WRKSRC}/VGB.html ${PREFIX}/share/doc/vgb
	@for i in ${WRKSRC}/demos/* ; \
	do \
		${INSTALL_DATA} $${i} ${PREFIX}/share/doc/vgb/demos ; \
	done
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>

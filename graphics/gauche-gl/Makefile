# New ports collection makefile for:	Gauche-gl
# Date created:				16 December 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	gl
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gauche
PKGNAMEPREFIX=	gauche-
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fuyuki@hadaly.org

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/Gauche-${PORTNAME}
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"

EXAMPLESDIR=	${PREFIX}/share/examples/gauche/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PLIST_SUB=	VERSION="`gauche-config -V`" \
		TARGET="${CONFIGURE_TARGET}"

do-install:
	cd ${WRKSRC}/src; ${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC}/lib; ${MAKE} ${INSTALL_TARGET}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	hugs
# Date created:		22 September 1997
# Whom:			Torsten Teg Grust (Torsten.Grust@uni-konstanz.de)
#
# $FreeBSD$
#

PORTNAME=	hugs98
PORTVERSION=	200211
CATEGORIES=	lang haskell
MASTER_SITES=	http://cvs.haskell.org/Hugs/downloads/${HUGS_DATE}/
DISTNAME=	${PORTNAME}-${HUGS_DATE}

MAINTAINER=	obraun@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src

HUGS_DATE=	Nov2002
USE_REINPLACE=	yes
USE_BISON=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-ffi
ALL_TARGET=	default ffihugs

MAN1=		hugs.1

post-patch:
	@${REINPLACE_CMD} -e 's|^\(install		:: install_notes\)|#\1|' \
		${WRKSRC}/MkInstal.in

do-configure:
	@(cd ${WRKSRC}/unix && ./configure ${CONFIGURE_ARGS})

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../docs/*.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../docs/server* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../Credits ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../License ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../Readme ${DOCSDIR}
.endif

.include <bsd.port.mk>

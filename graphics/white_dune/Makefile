# ex:ts=8
# Ports collection makefile for:	white_dune
# Date created:			Apr 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	white_dune
PORTVERSION=	0.19b31
CATEGORIES=	graphics
MASTER_SITES=	http://www.csv.ica.uni-stuttgart.de/vrml/dune/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_BISON=	yes
USE_MESA=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	# empty

MAN1=	dune.1

post-patch:
	@${GREP} -lR "malloc.h" ${WRKSRC} | ${XARGS} \
		${PERL} -pi -e "s/malloc\.h/stdlib.h/g"
	@${PERL} -pi -e "s/values\.h/limits.h/g" ${WRKSRC}/stdafx.h
	@${PERL} -pi -e "s/alloca\.h/stdlib.h/g" ${WRKSRC}/NodeNurbsSurface.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dune ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: David Holm <david@realityrift.com>
# $FreeBSD$

PORTNAME=	sgl
PORTVERSION=	2.0a3
CATEGORIES=	devel
MASTER_SITES=	http://www1.cs.columbia.edu/dcc/nestor/presentations/SGL/ \
		ftp://ftp.cs.rpi.edu/pub/stl/
DISTNAME=	SGL-${PORTVERSION}

MAINTAINER=	david@realityrift.com
COMMENT=	STL implementation for ADA95

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/lib/SGL
	${MKDIR} ${PREFIX}/share/SGL
	${MKDIR} ${PREFIX}/share/SGL/examples

	for i in `cat pkg-plist|grep -v dirrm|grep "lib/SGL"|sed "s/lib\/SGL\///"`; do \
			${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/sgl/$${i} ${PREFIX}/lib/SGL; \
	done

	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/copyright ${PREFIX}/share/SGL
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/readme ${PREFIX}/share/SGL

	for i in `cat pkg-plist|grep -v dirrm|grep "share/SGL/examples"|sed "s/share\/SGL\/examples\///"`; do \
			${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/test/$${i} ${PREFIX}/share/SGL/examples; \
	done

post-install:
	@${ECHO}
	@${ECHO} "Files have been installed into ${PREFIX}/lib/SGL"
	@${ECHO}

.include <bsd.port.post.mk>

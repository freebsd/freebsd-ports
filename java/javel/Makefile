# ex:ts=8
# Ports collection makefile for:	javel
# Date created:			Jan 30, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	javel
PORTVERSION=	0.3.2
CATEGORIES=	java
MASTER_SITES=	http://www.geocities.com/l.gregoire/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java disassembler

NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
MAKEFILE=	makefile

MAN1=		javel.1
PLIST_FILES=	bin/javel

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g ; \
		s,CC,CXX,g ; s,CFLAGS,CXXFLAGS,g" ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/javel ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/javel.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>

# ex:ts=8
# Ports collection makefile for:	duplo
# Date created:			Oct 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	duplo
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Find duplicated code blocks in large C/C++/Java/C#/VB.Net systems

USE_GMAKE=	yes

PLIST_FILES=	bin/duplo %%DATADIR%%/duplo.xsl
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC," \
		-e "s,^CXXFLAGS,#CXXFLAGS," \
		-e "s,[$$]{CC},$$\{CXX\}," \
		${WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/duplo ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/duplo.xsl ${DATADIR}

.include <bsd.port.mk>

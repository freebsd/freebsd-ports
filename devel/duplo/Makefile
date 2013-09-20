# Created by: ijliao
# $FreeBSD$

PORTNAME=	duplo
PORTVERSION=	0.2.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find duplicated code blocks in large C/C++/Java/C#/VB.Net systems

USE_GMAKE=	yes

PLIST_FILES=	bin/duplo %%DATADIR%%/duplo.xsl
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
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

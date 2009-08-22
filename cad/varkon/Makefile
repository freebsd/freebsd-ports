# New ports collection makefile for:	Varkon
# Date created:		19 April 2003
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	varkon
PORTVERSION=	1.19D
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Varkon_${PORTVERSION}
DISTNAME=	Varkon_sources_${PORTVERSION}
DIST_SUBDIR=	varkon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free CAD system and applications development tool

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_GL=		yes
USE_GMAKE=	yes
USE_XORG=	xpm
ALL_TARGET=
VARKON_ROOT=	${WRKDIR}/Varkon_${PORTVERSION}
WRKSRC=		${VARKON_ROOT}/sources
USE_DOS2UNIX=	Makefile

VARKON_PREFIX=	${PREFIX}/share/varkon
WEB_BROWSER?=	firefox

do-configure:
	@${REINPLACE_CMD} -e 's+%%VARKON_PREFIX%%+${VARKON_PREFIX}+ ; s+%%DOCSDIR%%+${DOCSDIR}+g ' \
	     ${VARKON_ROOT}/com/english/varkon
	@${FIND} ${WRKSRC} -name 'Makefile.FreeBSD' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's+/usr/local+${LOCALBASE}+g'
	@${FIND} ${WRKSRC} -name 'Makefile*' | ${XARGS} ${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g'

do-install:
	@${MKDIR} ${VARKON_PREFIX}/bin
	@${INSTALL_PROGRAM} ${VARKON_ROOT}/bin/* \
	  ${VARKON_PREFIX}/bin
	@${CP} -R ${VARKON_ROOT}/erm ${VARKON_PREFIX}
	@${CP} -R ${VARKON_ROOT}/lib ${VARKON_PREFIX}
	@${MKDIR} ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/fnt ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/icons ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/plt ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/tol ${VARKON_PREFIX}/cnf
	@${MKDIR} ${VARKON_PREFIX}/cnf/ini
	@${INSTALL} ${VARKON_ROOT}/cnf/ini/english/linux \
	  ${VARKON_PREFIX}/cnf/ini/freebsd
	@${CP} -R ${VARKON_ROOT}/mdf ${VARKON_PREFIX}/mdf
	@${INSTALL_SCRIPT} ${VARKON_ROOT}/com/english/varkon \
	  ${PREFIX}/bin
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}	#Varkon Manual
	@${CP} -R ${VARKON_ROOT}/man/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

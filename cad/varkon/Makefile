# New ports collection makefile for:	Varkon
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	varkon
PORTVERSION=	1.17D
CATEGORIES=	cad
MASTER_SITES=	http://www.tech.oru.se/cad/varkon/pub/linux/
DISTNAME=	${PORTNAME}_sources_${PORTVERSION}

MAINTAINER=	giffunip@yahoo.com
COMMENT=	A free CAD system and applications development tool

USE_MESA=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
VARKON_ROOT=	${WRKDIR}/${PORTNAME}_${PORTVERSION}
WRKSRC=		${VARKON_ROOT}/sources
MAKE_ENV+= VARKON_ROOT=${VARKON_ROOT}

VARKON_PREFIX=	${PREFIX}/share/varkon

post-patch:
	@${REINPLACE_CMD} -e 's+%%MAKE%%+${GMAKE}+g;' ${WRKSRC}/make_varkon
	@${REINPLACE_CMD} -e 's+%%VARKON_PREFIX%%+${VARKON_PREFIX}+ ; s+%%DOCSDIR%%+${DOCSDIR}+g ' \
	     ${VARKON_ROOT}/com/english/varkon
do-build:
	@(cd ${WRKSRC};${SETENV} ${MAKE_ENV} ${SH} make_varkon )

do-install:
	@${INSTALL} ${VARKON_ROOT}/com/english/varkon \
	  ${PREFIX}/bin
	@${MKDIR} ${VARKON_PREFIX}/bin
	@${INSTALL_PROGRAM} ${VARKON_ROOT}/bin/* \
	  ${VARKON_PREFIX}/bin
	@${CP} -R ${VARKON_ROOT}/app ${VARKON_PREFIX}
	@${CP} -R ${VARKON_ROOT}/mdf/english ${VARKON_PREFIX}/mdf
	@${CP} -R ${VARKON_ROOT}/erm ${VARKON_PREFIX}
	@${CP} -R ${VARKON_ROOT}/pid ${VARKON_PREFIX}
	@${CP} -R ${VARKON_ROOT}/lib ${VARKON_PREFIX}
	@${MKDIR} ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/fnt ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/plt ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/icons ${VARKON_PREFIX}/cnf
	@${CP} -R ${VARKON_ROOT}/cnf/tol ${VARKON_PREFIX}/cnf
	@${MKDIR} ${VARKON_PREFIX}/cnf/ini
	@${INSTALL} ${VARKON_ROOT}/cnf/ini/english/linux \
	  ${VARKON_PREFIX}/cnf/ini/freebsd
#.if !defined(NOPORTDOCS)
#	@${MKDIR} ${DOCSDIR}
#	@${CP} -R ${VARKON_ROOT}/man ${DOCSDIR}
#.endif

.include <bsd.port.mk>

# New ports collection makefile for:	Varkon
# Date created:		19 April 2003
# Whom:			Pedro Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	varkon
PORTVERSION=	1.17D
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.tech.oru.se/cad/varkon/pub/linux/:sources \
		http://www.tech.oru.se/cad/varkon/:docs
DISTFILES=	${PORTNAME}_sources_${PORTVERSION}${EXTRACT_SUFX}:sources \
		v_man.zip:docs m_man.zip:docs
DIST_SUBDIR=	varkon
EXTRACT_ONLY=	${PORTNAME}_sources_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free CAD system and applications development tool

.ifndef	NOPORTDOCS
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

USE_GL=		yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
VARKON_ROOT=	${WRKDIR}/${PORTNAME}_${PORTVERSION}
WRKSRC=		${VARKON_ROOT}/sources
MAKE_ENV+=	VARKON_ROOT=${VARKON_ROOT}

VARKON_PREFIX=	${PREFIX}/share/varkon
WEB_BROWSER?=	mozilla

post-patch:
	@${REINPLACE_CMD} -e 's+%%MAKE%%+${GMAKE}+g;' ${WRKSRC}/make_varkon
	@${REINPLACE_CMD} -e 's+netscape+${WEB_BROWSER}+ ' \
	     ${VARKON_ROOT}/cnf/ini/english/linux
	@${REINPLACE_CMD} -e 's+%%VARKON_PREFIX%%+${VARKON_PREFIX}+ ; s+%%DOCSDIR%%+${DOCSDIR}+g ' \
	     ${VARKON_ROOT}/com/english/varkon
do-build:
	@(cd ${WRKSRC};${SETENV} ${MAKE_ENV} ${SH} make_varkon )

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
	@${CP} -R ${VARKON_ROOT}/mdf/english ${VARKON_PREFIX}/mdf
	@${INSTALL_SCRIPT} ${VARKON_ROOT}/com/english/varkon \
	  ${PREFIX}/bin
.ifndef NOPORTDOCS
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${VARKON_ROOT}/app ${EXAMPLESDIR}
	@${CP} -R ${VARKON_ROOT}/pid ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}	#Varkon Manual
	@unzip ${DISTDIR}/${DIST_SUBDIR}/v_man	\
		-d ${DOCSDIR}
	@unzip -uo ${DISTDIR}/${DIST_SUBDIR}/m_man	\
		-d ${DOCSDIR}
.endif

.include <bsd.port.mk>

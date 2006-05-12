# New ports collection makefile for:	py-sip
# Date created:		Tue Oct  8 09:51:22 SAST 2002
# Whom:			nbm
#
# $FreeBSD$

PORTNAME=	sip
PORTVERSION=	4.4.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/sip4/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sip-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python to C and C++ bindings generator

USE_PYTHON=	yes

OPTIONS=	DEBUG "Build with debugging symbols" off \
		DOCS "Install documentation" on

DATADIR=	${PREFIX}/share/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

ARGS=		-b ${PREFIX}/bin -d ${PYTHONPREFIX_SITELIBDIR} \
		-e ${PYTHONPREFIX_INCLUDEDIR} -v ${DATADIR}

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS) || defined(WITHOUT_DOCS)
PLIST_SUB+=	DOCS="@comment "
.else
PLIST_SUB+=	DOCS=""
.endif
.if defined(WITH_DEBUG)
ARGS+=		-u
.endif

do-configure:
	( cd ${WRKSRC} && ${PYTHON_CMD} configure.py ${ARGS} )

post-install:
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	( ${MKDIR} -m 0755 ${DOCSDIR} && cd ${WRKSRC} && ${INSTALL_DATA} \
		doc/default.css doc/sipref.txt doc/sipref.html \
		NEWS LICENSE ${DOCSDIR} )
.endif
	( ${MKDIR} -m 0755 ${DATADIR} && \
		cd ${PYTHONPREFIX_SITELIBDIR} && \
		${PYTHON_CMD} -c "import sipconfig" && \
		${PYTHON_CMD} -O -c "import sipconfig" && \
		${PYTHON_CMD} -c "import sipdistutils" && \
		${PYTHON_CMD} -O -c "import sipdistutils" )

.include <bsd.port.post.mk>

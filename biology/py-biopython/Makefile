# New ports collection makefile for:	py-biopython
# Date created:		28 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	biopython
PORTVERSION=	1.00.a3
CATEGORIES=	biology python
MASTER_SITES=	http://www.biopython.org/Download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/a/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Martel/__init__.py:${PORTSDIR}/textproc/py-martel \
		${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric \
		${PYTHON_SITELIBDIR}/mx/TextTools/__init__.py:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes
PLIST_SUB+=	PLIST_CORBA=${PLIST_CORBA} PLIST_OMNIORB=${PLIST_OMNIORB} \
		PLIST_FNORB=${PLIST_FNORB}
CPIO=		cpio --quiet -pdum -R
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

# CORBA support (a.k.a Biopython-CORBA):
# Set WITH_CORBA to enable CORBA support for the Biopython port.
.if defined(WITH_CORBA)

# CORBA_ORB may be set from the command line to either "omniorb", "fnorb"
# or "orbit".
# - omniORB is a commercial quality, high speed ORB.  The installation is
#   huge and building the C++ source is a lengthy process.  The omniORBpy
#   Python bindings are used.
# - Fnorb is a tiny, lightweight ORB and is excellent for testing purposes.
# - ORBit is a very popular and elegant ORB.  The ORBit-Python bindings are
#   used.
# Since Fnorb is distributed under a non-free licence and ORBit support in
# Biopython-CORBA is reputedly not yet stable, "omniorb" is the default.
CORBA_ORB?=	omniorb

CORBA_VERSION=	0.2.1
CORBA_DISTNAME=	biopython-corba-${CORBA_VERSION}
CORBA_WRKSRC=	${WRKDIR}/${CORBA_DISTNAME}
DISTFILES+=	${CORBA_DISTNAME}${EXTRACT_SUFX}
PLIST_CORBA=	""

.if ${CORBA_ORB} == "omniorb"
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/omniORB/__init__.py:${PORTSDIR}/devel/py-omniorb
CORBA_ORBNAME=	omniORB
PLIST_OMNIORB=	""
PLIST_FNORB=	"@comment "
.elif ${CORBA_ORB} == "fnorb"
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/Fnorb/__init__.py:${PORTSDIR}/devel/fnorb
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Fnorb/__init__.py:${PORTSDIR}/devel/fnorb
CORBA_ORBNAME=	Fnorb
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-build_helper.py
PLIST_OMNIORB=	"@comment "
PLIST_FNORB=	""
.elif ${CORBA_ORB} == "orbit"
RUN_DEPENDS+=	${LOCALBASE}/include/orbit-python/orbit-python.h:${PORTSDIR}/devel/py-orbit
CORBA_ORBNAME=	ORBit
PLIST_OMNIORB=	"@comment "
PLIST_FNORB=	"@comment "
.endif

.else
PLIST_CORBA=	"@comment "
PLIST_OMNIORB=	"@comment "
PLIST_FNORB=	"@comment "
.endif	# defined(WITH_CORBA)

pre-fetch:
.if !defined(BATCH) && !defined(WITH_CORBA)
	@ ${CAT} ${FILESDIR}/corba.msg
.endif

post-configure:
.if defined(WITH_CORBA)
	@ ${PERL} -pi.orig -e \
	  "/^orb_implementation/ && s/omniORB/${CORBA_ORBNAME}/" \
	  ${CORBA_WRKSRC}/BioCorba/biocorbaconfig.py
.endif

do-build:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py build
.if defined(WITH_CORBA)
	@ cd ${CORBA_WRKSRC} && ${PYTHON_CMD} setup.py build
.endif

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 \
	  --prefix=${PREFIX}
.if defined(WITH_CORBA)
	@ cd ${CORBA_WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 \
	  --prefix=${PREFIX}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfiles in *.txt *.tex *.py
	@ ${INSTALL_DATA} ${WRKSRC}/Doc/${docfiles} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/Doc/examples/*.py ${EXAMPLESDIR}
	@ cd ${WRKSRC} && find Scripts \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.if defined(WITH_CORBA)
	@ ${MKDIR} ${DOCSDIR}/BioCorba
.for docfiles in *.tex *.pdf
	@ ${INSTALL_DATA} ${CORBA_WRKSRC}/Doc/${docfiles} ${DOCSDIR}/BioCorba
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}/BioCorba
	@ cd ${CORBA_WRKSRC}/Doc/examples && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}/BioCorba
	@ ${MKDIR} ${EXAMPLESDIR}/BioCorba/Scripts
	@ ${INSTALL_DATA} ${CORBA_WRKSRC}/Scripts/* \
	  ${EXAMPLESDIR}/BioCorba/Scripts
.endif	# defined(WITH_CORBA)
.endif	# !defined(NOPORTDOCS)

.include <bsd.port.mk>

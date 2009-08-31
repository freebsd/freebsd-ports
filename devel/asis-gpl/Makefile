# New ports collection makefile for: asis-gpl
# Date created:		31 Dec 2006
# Whom:			John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	asis-gpl
PORTVERSION=	2006
CATEGORIES=	devel
MASTER_SITES=	http://libre.adacore.com/
EXTRACT_SUFX=	-src.tgz

MAINTAINER=	john_m_cooper@yahoo.com
COMMENT=	An Ada ASIS implementation including the Data Decomposition Annex

BUILD_DEPENDS=	gnatmake:${PORTSDIR}/lang/gnat
RUN_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

CONFLICTS=	asis-3.15*
BROKEN=		does not build

USE_GMAKE=	yes

ASIS_SRC=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

# Check for GNAT sources.
.if !exists(${DISTDIR}/${ASIS_SRC}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=:\n\
Because of licensing and registration restrictions, you must fetch the\n\
source distribution manually.  Please access http://libre.adacore.com/\n\
with a web browser, register (it's free), and log in.  Download the source\n\
files:\n\
\t${ASIS_SRC}\n\
and place them in ${DISTDIR}.\n
.endif

WRKSRC=		${WRKDIR}/asis-${PORTVERSION}-src
DOCSDIR=	${PREFIX}/share/doc/asis

INSTALL_TARGET=	all

post-patch:
	@${REINPLACE_CMD} -E -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/asis/a4g-contt.ads
	@${REINPLACE_CMD} -E -e 's|%%CFLAGS%%|${CFLAGS}|' \
		${WRKSRC}/Makefile.stub

do-build:
	@${ECHO_MSG} "This port does everything in the install step."
	@${ECHO_MSG} "The build step is a no-op."

# Both info files lack entry fields, and so this manual hack
# (and a dir entry in pkg-plist) are necessary
post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-docs)
	@install-info --entry "ASIS Reference Manual" \
		${DOCSDIR}/info/asis_rm.info \
		${DOCSDIR}/info/dir
	@install-info --entry "ASIS User Guide" \
		${DOCSDIR}/info/asis_ug.info \
		${DOCSDIR}/info/dir
.endif

.include <bsd.port.post.mk>

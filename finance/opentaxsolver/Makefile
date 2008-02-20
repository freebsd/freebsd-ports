# Ports collection makefile for:  opentaxsolver
# Date created:			  Sat Apr 08, 2006
# Whom:				  John Hein (jhein@timing.com)
#
# $FreeBSD$
#

PORTNAME=	${UPPORTNAME:L}
PORTVERSION=	5.04
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	opentaxsolver
DISTNAME=	${UPPORTNAME}2007_${PORTVERSION}
EXTRACT_SUFX=	0.tgz

MAINTAINER=	jhein@timing.com
COMMENT=	US tax prep software

USE_XLIB=	yes
USE_GL=		yes
UPPORTNAME=	OpenTaxSolver

post-patch:
	@${REINPLACE_CMD} -e 's/%%PREFIX%%/${PREFIX:C,/,\/,g}/' \
	${WRKSRC}/src/GUI/ots_gui.c
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|' \
	${WRKSRC}/src/GUI/Makefile.linux

# 4.07 distfile has pre-built (linux) binaries we must whack.
pre-build:
	@(cd ${BUILD_WRKSRC}/src && make -f Makefile.unix clean && \
	cd GUI && make -f Makefile.linux clean)

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
	./Build_taxsolve_packages_LINUX.sh)

BUILDPROGLISTCMD=	${FIND} bin -type f
BUILDEXAMPLELISTCMD=	${FIND} examples_and_templates -type f
BUILDEXAMPLEDIRLISTCMD=	${FIND} examples_and_templates -type d
NEWPLIST=		${WRKDIR}/plist.new

do-install:
	@(cd ${WRKSRC} && \
	for prog in $$(${BUILDPROGLISTCMD}); do \
	    ${INSTALL_PROGRAM} $${prog} ${PREFIX}/bin/. ; \
	done && \
	${MKDIR} ${PREFIX}/share/ots && \
	${INSTALL_DATA} src/GUI/otslogo.ppm ${PREFIX}/share/ots/. && \
	for example in $$(${BUILDEXAMPLELISTCMD}); do \
	    ${MKDIR} ${PREFIX}/share/ots/$$(dirname $${example}) && \
	    ${INSTALL_DATA} $${example} \
	    ${PREFIX}/share/ots/$$(dirname $${example})/. ; \
	done)

new-plist:
	@(cd ${WRKSRC} && \
	${BUILDPROGLISTCMD} | ${SORT} > ${NEWPLIST} && \
	${ECHO_CMD} share/ots/otslogo.ppm >> ${NEWPLIST} && \
	${BUILDEXAMPLELISTCMD} | ${SED} 's,^,share/ots/,' | ${SORT} \
	    >> ${NEWPLIST} && \
	for f in $$(${BUILDEXAMPLEDIRLISTCMD} | ${SED} 's,^,share/ots/,' && \
	    ${ECHO_CMD} share/ots); do ${ECHO_CMD} @dirrm $$f; done | \
	    ${SORT} -r >> ${NEWPLIST})

.include <bsd.port.mk>

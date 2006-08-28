# Ports collection makefile for:  opentaxsolver
# Date created:			  Sat Apr 08, 2006
# Whom:				  John Hein (jhein@timing.com)
#
# $FreeBSD$
#

PORTNAME=	${UPPORTNAME:L}
PORTVERSION=	3.07
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	opentaxsolver
DISTNAME=	${UPPORTNAME}2005_3.07
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhein@timing.com
COMMENT=	US tax prep software

USE_XLIB=	yes
UPPORTNAME=	OpenTaxSolver

post-patch:
	@${REINPLACE_CMD} -e 's/%%PREFIX%%/${PREFIX:C,/,\/,g}/' \
	${WRKSRC}/src/GUI/ots_gui.c

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
	./Build_taxsolve_packages_LINUX.sh)

BUILDPROGLISTCMD=	${FIND} bin -type f
BUILDEXAMPLELISTCMD=	${FIND} examples_and_templates -type f
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
	${BUILDPROGLISTCMD} > ${NEWPLIST} && \
	${ECHO_CMD} share/ots/otslogo.ppm >> ${NEWPLIST} && \
	${BUILDEXAMPLELISTCMD} | ${SED} 's,^,share/ots/,' >> ${NEWPLIST})

.include <bsd.port.mk>

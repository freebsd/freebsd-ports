# Ports collection makefile for:  opentaxsolver
# Date created:			  Sat Apr 08, 2006
# Whom:				  John Hein (jhein@timing.com)
#
# $FreeBSD$
#

PORTNAME=	${UPPORTNAME:L}
PORTVERSION=	9.01
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/OTS_${TAXYEAR}/v${PORTVERSION}
DISTNAME=	${UPPORTNAME}${TAXYEAR}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhein@symmetricom.com
COMMENT=	US tax prep software

PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-plist
SUB_LIST=	TAXYEAR=${TAXYEAR}
TAXYEAR=	2011
UPPORTNAME=	OpenTaxSolver

.if !defined(WITHOUT_X11)
USE_GL=		yes
USE_XORG=	xmu xext x11
USE_PKGCONFIG=	yes
CPPFLAGS+=	$$(pkg-config --cflags-only-I glu xext xmu)
LDFLAGS+=	$$(pkg-config --libs-only-L glu xext xmu)
SUB_LIST+=	X11=
.else
MAKE_ENV+=	WITHOUT_X11=yes
SUB_LIST+=	X11="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/%%PREFIX%%/${PREFIX:C,/,\/,g}/' \
	${WRKSRC}/src/GUI/ots_gui.c

# 9.00 distfile has pre-built (linux) binaries we must whack.
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
	for example in $$(${BUILDEXAMPLELISTCMD}); do \
	    ${MKDIR} ${PREFIX}/share/ots/$$(dirname $${example}) && \
	    ${INSTALL_DATA} $${example} \
	    ${PREFIX}/share/ots/$$(dirname $${example})/. ; \
	done)

new-plist:
	@(cd ${WRKSRC} && \
	${BUILDPROGLISTCMD} | ${SORT} > ${NEWPLIST} && \
	${BUILDEXAMPLELISTCMD} | ${SED} 's,^,share/ots/,' | ${SORT} \
	    >> ${NEWPLIST} && \
	for f in $$(${BUILDEXAMPLEDIRLISTCMD} | ${SED} 's,^,share/ots/,' && \
	    ${ECHO_CMD} share/ots); do ${ECHO_CMD} @dirrm $$f; done | \
	    ${SORT} -r >> ${NEWPLIST})

.include <bsd.port.mk>

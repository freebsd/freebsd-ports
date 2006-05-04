# Ports collection makefile for: spin
# Date created:		Oct 23, 1997
# Whom:			jhanna@home.com
#
# $FreeBSD$
#

PORTNAME=	spin
PORTVERSION=	4.2.6
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/
DISTNAME=	spin${PORTVERSION:S/.//g}

MAINTAINER=	jhanna@shaw.ca
COMMENT=	An on-the-fly verification system for asynchronous concurrent systems

OPTIONS=	XSPIN "Install xspin and TCL/Tk dependency" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XSPIN)
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
PLIST_SUB+=	XSPIN=""
XSPIN_TCL	=${WRKDIR}/Spin/Xspin4.2/xspin426.tcl
.else
PLIST_SUB+=	XSPIN="@comment "
.endif

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Spin/Src${PORTVERSION}
MAKEFILE=	makefile
ALL_TARGET=	spin
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNXT"

post-extract:
	@cd ${WRKDIR}/Spin/Test && ${SH} ${WRKDIR}/Spin/Test/examples

.if !defined(WITHOUT_XSPIN)
pre-patch:
	${TR} -d '\015' < ${XSPIN_TCL} > ${XSPIN_TCL}.tmp
	${MV} -f ${XSPIN_TCL}.tmp ${XSPIN_TCL}
.endif

.if !defined(WITHOUT_XSPIN)
post-patch:
	@WISH=`(cd ${LOCALBASE}/bin ; ${LS} wish8* ) | tail -1` ; \
	if [ -z "$$WISH" ] ; then WISH=wish8.0 ; fi ; \
	${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g;" \
		-e "s|%%WISH%%|$$WISH|g" ${XSPIN_TCL}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${PREFIX}/bin
.if !defined(WITHOUT_XSPIN)
	${INSTALL_SCRIPT} ${XSPIN_TCL} ${PREFIX}/bin/xspin
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/Doc
	${MKDIR} ${DOCSDIR}/Examples
	${MKDIR} ${DOCSDIR}/Test
	${INSTALL_DATA} ${WRKDIR}/Spin/Doc/* ${DOCSDIR}/Doc
	${INSTALL_DATA} ${WRKDIR}/Spin/Test/ex.* ${DOCSDIR}/Examples
.for i in README.tests abp eratosthenes hello leader leader.ltl leader2 \
	leader_trace loops mobile1 mobile1.ltl mobile2 mobile2.ltl \
	pathfinder peterson petersonN pftp priorities snoopy sort wordcount
	${INSTALL_DATA} ${WRKDIR}/Spin/Test/$i ${DOCSDIR}/Test
.endfor
	${INSTALL_MAN} ${WRKDIR}/Spin/Man/spin.1 ${PREFIX}/man/man1

MANPAGE_WRKSRC=	${WRKDIR}/Spin/Man
MAN1=		spin.1
.endif

.include <bsd.port.post.mk>

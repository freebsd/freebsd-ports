# Created by: jhanna@home.com
# $FreeBSD$

PORTNAME=	spin
PORTVERSION=	5.2.2
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/
DISTNAME=	spin${PORTVERSION:S/.//g}

MAINTAINER=	jhanna@shaw.ca
COMMENT=	On-the-fly verification system for asynchronous concurrent systems

OPTIONS_DEFINE=	XSPIN DOCS
OPTIONS_DEFAULT=	XSPIN
XSPIN_DESC=	Install xspin and TCL/Tk dependency

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXSPIN}
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
PLIST_SUB+=	XSPIN=""
XSPIN_TCL=	${WRKDIR}/Spin/Xspin5.2/xspin521.tcl
.else
PLIST_SUB+=	XSPIN="@comment "
.endif

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Spin/Src${PORTVERSION}
MAKEFILE=	makefile
ALL_TARGET=	spin
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNXT"
MAKE_JOBS_UNSAFE=yes

post-extract:
	@${ECHO_MSG} "Unbundling promela example files..."
	@cd ${WRKDIR}/Spin/Test && ${SH} ${WRKDIR}/Spin/Test/examples

.if ${PORT_OPTIONS:MXSPIN}
pre-patch:
	@${TR} -d '\r' < ${XSPIN_TCL} > ${XSPIN_TCL}.tmp
	@${MV} -f ${XSPIN_TCL}.tmp ${XSPIN_TCL}
.endif

.if ${PORT_OPTIONS:MXSPIN}
post-patch:
	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g;" \
		-e "s|%%WISH%%|wish8.4|g" ${XSPIN_TCL}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${PREFIX}/bin
.if ${PORT_OPTIONS:MXSPIN}
	${INSTALL_SCRIPT} ${XSPIN_TCL} ${PREFIX}/bin/xspin
.endif
.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.mk>

# Ports collection makefile for: spin
# Date created:		Oct 23, 1997
# Whom:			jhanna@home.com
#
# $FreeBSD$
#

PORTNAME=	spin
PORTVERSION=	3.5.0
CATEGORIES=	devel
MASTER_SITES=	http://spinroot.com/spin/Src/ \
		ftp://netlib.bell-labs.com/netlib/spin/ \
		ftp://www.netlib.org/spin/
DISTFILES=	spin${PORTVERSION:S/.//g}.tar.gz html.tar.gz

MAINTAINER=	jhanna@shaw.ca

DIST_SUBDIR=	spin
WRKSRC=		${WRKDIR}/Src3.5.0
MAKEFILE=	makefile
ALL_TARGET=	spin
USE_REINPLACE=	yes

post-extract:
	@cd ${WRKDIR}/Test && ${SH} ${WRKDIR}/Test/examples

post-patch:
	@WISH=`(cd ${LOCALBASE}/bin ; ls wish8* ) | tail -1` ; \
	if [ -z "$$WISH" ] ; then WISH=wish8.0 ; fi ; \
	${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g;" \
		-e "s|%%WISH%%|$$WISH|g" ${WRKDIR}/Xspin3.5/xspin350.tcl

pre-build:
	cd ${WRKSRC} && ${MAKE} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spin ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/Xspin3.5/xspin350.tcl ${PREFIX}/bin
	${RM} -f ${PREFIX}/bin/xspin
	${LN} -s ${PREFIX}/bin/xspin350.tcl ${PREFIX}/bin/xspin

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/spin/Doc
	${MKDIR} ${PREFIX}/share/doc/spin/Examples
	${MKDIR} ${PREFIX}/share/doc/spin/HTML
	${MKDIR} ${PREFIX}/share/doc/spin/Test
	${INSTALL_DATA} ${WRKDIR}/Doc/* ${PREFIX}/share/doc/spin/Doc
	${INSTALL_DATA} ${WRKDIR}/Test/ex.* ${PREFIX}/share/doc/spin/Examples
	${INSTALL_DATA} ${WRKDIR}/HTML/* ${PREFIX}/share/doc/spin/HTML
.for i in README.tests abp erathostenes hello leader leader.ltl leader2 \
	loops mobile1 mobile1.ltl mobile2 mobile2.ltl pathfinder peterson petersonN pftp priorities snoopy sort wordcount
	${INSTALL_DATA} ${WRKDIR}/Test/$i ${PREFIX}/share/doc/spin/Test
.endfor
.endif

.include <bsd.port.mk>

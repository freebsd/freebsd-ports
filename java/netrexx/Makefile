# New ports collection makefile for:	NetRexx
# Date created:		Feb 8, 1999
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	NetRexx
PORTVERSION=	2.02
PORTREVISION=	3
CATEGORIES=	java lang
MASTER_SITES=	http://www2.hursley.ibm.com/netrexx/
DISTNAME=	NetRexx

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Human-oriented programming language for writing/using Java classes

RUN_DEPENDS=	${LOCALBASE}/bin/rexx:${PORTSDIR}/lang/rexx-imc

BROKEN=		Unfetchable

NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes

pre-patch:
	for file in ${WRKSRC}/bin/NetRexxC.sh ${WRKSRC}/read.me.first; do \
	    ${TR} -d '\015' < $${file} > $${file}.new; \
	    ${MV} $${file}.new $${file}; \
	done

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/NetRexxC.sh ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/NetRexxC.sh ${PREFIX}/bin/nrc
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/NetRexxC.cmd \
		${PREFIX}/bin/NetRexxC.rexx
	@${LN} -sf ${PREFIX}/bin/NetRexxC.rexx ${PREFIX}/bin/nrc.rexx

	@${MKDIR} ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/lib/NetRexxC.jar ${PREFIX}/share/java/classes
	@${INSTALL_DATA} ${WRKSRC}/runlib/NetRexxR.jar ${PREFIX}/share/java/classes

.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/bin/hello.nrx \
		${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}/netrexx/lang
.for dir in netrexx/lang .
	@${INSTALL_DATA} ${WRKSRC}/browse/${dir}/* ${DOCSDIR}/${dir}
	@${RM} -Rf ${WRKSRC}/browse/netrexx
.endfor
.endif

post-install:
	@${ECHO} "====================  IBM LICENSE  ===================="
	@${CAT} ${WRKSRC}/browse/license.txt
	@${ECHO} "-------------------------------------------------------"
	@${ECHO} "====================  IMPORTANT!!  ===================="
	@${CAT} ${WRKSRC}/read.me.first

.include <bsd.port.mk>

# New ports collection makefile for:	NetRexx
# Date created:		Feb 8, 1999
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	netrexx
PORTVERSION=	1.160
PORTREVISION=	1
CATEGORIES=	java lang
MASTER_SITES=	http://www.ibm.com/technology/NetRexx/
DISTNAME=	NetRexx
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmcoopr@webmail.bmi.net

RUN_DEPENDS=	${PREFIX}/jdk${JDK_VERSION}/bin/java:${PORTSDIR}/java/jdk \
		rexx:${PORTSDIR}/lang/rexx-imc

NO_BUILD=	yes
# pkg/PLIST depends on the JDK_VERSION
JDK_VERSION?=	1.1.8
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}

ERASE_FILES=	NetRexxC.bat nrc.bat nrc.cmd hello.nrx

do-install:
	-${MV} ${WRKSRC}/nrtools.tar.Z ${WRKSRC}/.foo.Z
	uncompress -c ${WRKSRC}/.foo.Z | \
	    tar -xvf - -C ${PREFIX}/jdk${JDK_VERSION}
.for file in ${ERASE_FILES}
	@${RM} -f ${PREFIX}/jdk${JDK_VERSION}/bin/${file}
.endfor
	@${CP} ${FILESDIR}/NetRexxC.cmd.new ${PREFIX}/jdk${JDK_VERSION}/bin/NetRexxC.cmd
	@${LN} -sf ${PREFIX}/jdk${JDK_VERSION}/bin/NetRexxC.cmd \
		  ${PREFIX}/jdk${JDK_VERSION}/bin/nrc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/NetRexx
	@${CP} -R ${WRKSRC}/* ${PREFIX}/share/doc/NetRexx/
.endif

.include <bsd.port.mk>

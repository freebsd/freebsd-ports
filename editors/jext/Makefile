# New ports collection makefile for:    jext
# Date created:				17 Febrary 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jext
PORTVERSION=	3.0.2
PORTREVISION=	2
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jext

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful 100% pure Java text editor

RUN_DEPENDS=	${JAVAVM}:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/etc/javavms:${PORTSDIR}/java/jdk13

WRKSRC=		${WRKDIR}
USE_XLIB=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

JAVAVM?=	${LOCALBASE}/bin/javavm

INSTSBDR=	${PREFIX}/share/java/jext

do-configure:
	@${REINPLACE_CMD} -e 's|%%JAVAVM%%|${JAVAVM}|g ; \
		s|%%JEXT_HOME%%|${INSTSBDR}|g'	${WRKSRC}/bin/jext

do-install:
	@${MKDIR} ${INSTSBDR}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/jext ${PREFIX}/bin/jext
	@(cd ${WRKSRC} && ${TAR} -c -f - Jython-LICENSE LICENSE README \
		History.txt Names.txt bin lib) | \
		(cd ${INSTSBDR} && ${TAR} --unlink -x -f -)
	@CLASSPATH=${INSTSBDR}/lib/jython.jar javavm org.python.util.jython \
		${INSTSBDR}/lib/Lib/compileall.py ${INSTSBDR}

post-install:
	@${ECHO_MSG} "-------------------------------------------------------------------------------"
	@${ECHO_MSG} " Please note that Java2 platform (jdk/jre-1.2.x or later) is required to run"
	@${ECHO_MSG} " this program."
	@${ECHO_MSG} "-------------------------------------------------------------------------------"

.include <bsd.port.mk>

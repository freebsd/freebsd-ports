# New ports collection makefile for:	javavmwrapper
# Date created:				10 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	javavmwrapper
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	java
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Wrapper script for various Java Virtual Machines

CONFLICTS=	kaffe-1.* kaffe-devel-1.*

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PKGINSTALL=	${WRKDIR}/pkg-install

MAN1=		checkvms.1 javavm.1 registervm.1 unregistervm.1
MAN5=		javavms.5

SRC=		${.CURDIR}/src
SCRIPTS=	classpath javavmwrapper
# This is normally defined by bsd.java.mk when USE_JAVA is defined, but
# we can't do that here since it would result in a circular dependency
JAVALIBDIR=	${LOCALBASE}/share/java/classes

do-fetch:
	@${DO_NADA}

do-configure:
.for _script in ${SCRIPTS}
	${SED} -e 's|%%PREFIX%%|${PREFIX}|;' \
	       -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|;' \
		${SRC}/${_script}.sh >${WRKDIR}/${_script}.sh
.endfor
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|;' \
		${FILESDIR}/pkg-install.in > ${PKGINSTALL}
.for _man in checkvms.1 javavm.1 registervm.1 ${MAN5}
	${SED} -e 's|%%PREFIX%%|${PREFIX}|;' \
	       -e 's|%%LOCALBASE%%|${LOCALBASE}|;' \
	       -e 's|%%PORTSDIR%%|${PORTSDIR}|;' \
	       ${SRC}/${_man} > ${WRKDIR}/${_man}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/classpath.sh ${PREFIX}/bin/classpath
	${INSTALL_SCRIPT} ${WRKDIR}/javavmwrapper.sh ${PREFIX}/bin/javavm
	${LN} -sf ${PREFIX}/bin/javavm ${PREFIX}/bin/registervm
	${LN} -sf ${PREFIX}/bin/javavm ${PREFIX}/bin/unregistervm
	${LN} -sf ${PREFIX}/bin/javavm ${PREFIX}/bin/checkvms
.for _man in checkvms.1 javavm.1 registervm.1
	${INSTALL_MAN} ${WRKDIR}/${_man} ${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_MAN} ${WRKDIR}/registervm.1 \
		${MAN1PREFIX}/man/man1/unregistervm.1
	${INSTALL_MAN} ${WRKDIR}/${MAN5} ${MAN5PREFIX}/man/man5

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
		POST-INSTALL

.include <bsd.port.mk>

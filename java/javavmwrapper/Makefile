# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	javavmwrapper
PORTVERSION=	2.7.5
CATEGORIES=	java
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Wrapper script for various Java Virtual Machines

LICENSE=	BEERWARE BSD2CLAUSE
LICENSE_COMB=	multi
LICENSE_NAME_BEERWARE=	"THE BEER-WARE LICENSE" (Revision 42, (c) Poul-Henning Kamp)
LICENSE_TEXT_BEERWARE=	See ${SRC}/javavmwrapper.sh for license text
LICENSE_PERMS_BEERWARE=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

PKGINSTALL=	${WRKDIR}/pkg-install

SRC=		${.CURDIR}/src
SCRIPTS=	classpath javavmwrapper
# This is normally defined by bsd.java.mk when USE_JAVA is defined, but
# we can't do that here since it would result in a circular dependency
JAVALIBDIR=	${LOCALBASE}/share/java/classes

do-configure:
.for _script in ${SCRIPTS}
	${SED} -e 's|%%PREFIX%%|${PREFIX}|;' \
	       -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|;' \
		${SRC}/${_script}.sh >${WRKSRC}/${_script}.sh
.endfor
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|;' \
		${FILESDIR}/pkg-install.in > ${PKGINSTALL}
.for _man in checkvms.1 javavm.1 manvm.1 registervm.1 javavm_opts.conf.5 javavms.5
	${SED} -e 's|%%PREFIX%%|${PREFIX}|;' \
	       -e 's|%%LOCALBASE%%|${LOCALBASE}|;' \
	       -e 's|%%PORTSDIR%%|${PORTSDIR}|;' \
	       ${SRC}/${_man} > ${WRKSRC}/${_man}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/classpath.sh ${STAGEDIR}${PREFIX}/bin/classpath
	${INSTALL_SCRIPT} ${WRKSRC}/javavmwrapper.sh ${STAGEDIR}${PREFIX}/bin/javavm
	${LN} -sf javavm ${STAGEDIR}${PREFIX}/bin/checkvms
	${LN} -sf javavm ${STAGEDIR}${PREFIX}/bin/manvm
	${LN} -sf javavm ${STAGEDIR}${PREFIX}/bin/registervm
	${LN} -sf javavm ${STAGEDIR}${PREFIX}/bin/unregistervm
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/registervm.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/unregistervm.1
	${INSTALL_MAN} ${WRKSRC}/*.5 ${STAGEDIR}${MAN5PREFIX}/man/man5
	${INSTALL_DATA} ${FILESDIR}/javavm_opts.conf.dist \
		${STAGEDIR}${PREFIX}/etc/javavm_opts.conf.dist

.include <bsd.port.mk>

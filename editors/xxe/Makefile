# $FreeBSD$

PORTNAME=	xxe
PORTVERSION=	${XXE_VERSION}
CATEGORIES=	editors java
MASTER_SITES=	http://www.xmlmind.net/xmleditor/_download/ \
		http://www.xmlmind.com/xmleditor/_download/
PKGNAMESUFFIX=	-eval
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML editor featuring a word processor-like view

USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	YES

RESTRICTED=	Licensee may not distribute the software, evaluation edition

BINS=		convertdoc csscheck deploywebstart translatexxe xmltool xxe

PLIST_SUB=	XXE=${XXE_DIR}

post-extract:
		@${SED} -e 's,%%JAVA_HOME%%,${JAVA_HOME},' \
			-e 's,%%PREFIX%%,${PREFIX},' \
			-e 's,%%DISTNAME%%,${DISTNAME},' \
			${FILESDIR}/launcher > ${WRKDIR}/xxe

do-install:
		@cd ${WRKDIR} && tar cf - ${DISTNAME} | \
				 tar -C ${PREFIX}/lib -xf -
.for f in ${BINS}
		@${INSTALL_SCRIPT} ${WRKDIR}/xxe ${PREFIX}/bin/${f}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include "Makefile.inc"

.include <bsd.port.mk>

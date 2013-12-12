# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnspython
PORTVERSION=	1.11.1
CATEGORIES=	dns python
MASTER_SITES=	http://www.dnspython.org/kits${PORTVERSIONSUFFIX}/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSIONSUFFIX}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	DNS toolkit for Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}${PORTVERSIONSUFFIX}
PYDISTUTILS_NOEGGINFO=	yes

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS_DEFINE=	PYCRYPTO
PYCRYPTO_DESC=	Enable pycrypto (part of dnssec needs it)

PORTDOCS=	ChangeLog README
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

EXAMPLE_FILES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py \
		xfr.py zonediff.py
EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} < 3
PORTVERSIONSUFFIX=
PLIST=		${PKGDIR}/pkg-plist-py2
.else
PORTVERSIONSUFFIX=3
PLIST=		${PKGDIR}/pkg-plist-py3
EXAMPLESDIR:=	${EXAMPLESDIR}3
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHON_VER=${PYTHON_VER}

post-patch:
	for example in ${EXAMPLE_FILES} ; \
	  do ${REINPLACE_CMD} -e 's|python3|${PYTHON_VERSION}|1' \
	    ${WRKSRC}/examples/$${example} ; \
	done

post-install:
# docs
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
# examples
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for docfile in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${docfile} ${EXAMPLESDIR}
.endfor
.endif
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/dns/*
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/dns/*

.if ${PORT_OPTIONS:MPYCRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto
.endif

.include <bsd.port.post.mk>

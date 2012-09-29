# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnspython
PORTVERSION=	1.10.0
CATEGORIES=	dns python
MASTER_SITES=	http://www.dnspython.org/kits/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	A DNS toolkit for Python

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	PYCRYPTO
PYCRYPTO_DESC=	Enable pycrypto (part of dnssec needs it)

PORTDOCS=	ChangeLog README
EXAMPLE_FILES=	ddns.py e164.py mx.py name.py reverse.py reverse_name.py xfr.py \
		zonediff.py

.include <bsd.port.options.mk>

post-install:
# docs
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# examples
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/dns/*
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/dns/*

.if ${PORT_OPTIONS:MPYCRYPTO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}crypto>0:${PORTSDIR}/security/py-pycrypto
.endif

.include <bsd.port.mk>

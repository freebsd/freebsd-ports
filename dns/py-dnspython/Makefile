# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnspython
PORTVERSION=	1.9.4
CATEGORIES=	dns python
MASTER_SITES=	http://www.dnspython.org/kits/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DNS toolkit for Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

OPTIONS=	PYCRYPTO "Enable pycrypto (part of dnssec needs it)" off

PORTDOCS=	\
		ChangeLog \
		README \
		TODO
EXAMPLE_FILES=	\
		ddns.py \
		e164.py \
		mx.py \
		name.py \
		reverse.py \
		reverse_name.py \
		xfr.py \
		zonediff.py

post-install:
# docs
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# examples
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${file} ${EXAMPLESDIR}
.endfor
.endif
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/dns/*
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/dns/*

.include <bsd.port.pre.mk>

.if defined(WITH_PYCRYPTO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto
.endif

.include <bsd.port.post.mk>

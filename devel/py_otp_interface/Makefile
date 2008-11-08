# New ports collection makefile for:	py_otp_interface
# Date Created:				10 November 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py_otp_interface
PORTVERSION=	0.95
CATEGORIES=	devel python
MASTER_SITES=	http://www.lysator.liu.se/~tab/erlang/py_interface/
DISTNAME=	py_interface-${PORTVERSION}
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A native Python implementation of an Erlang/OTP node

USE_PYTHON=	yes

OTP_LIBS=	__init__.py erl_async_conn.py erl_common.py erl_epmd.py \
		erl_eventhandler.py erl_node.py erl_node_conn.py erl_opts.py \
		erl_term.py
OTP_DOCS=	COPYING.LIB README

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/py_interface
	@for FILE in ${OTP_LIBS}; do \
		${INSTALL_DATA} ${WRKSRC}/py_interface/$${FILE}* ${PYTHON_SITELIBDIR}/py_interface; \
	done
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR};
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${OTP_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>

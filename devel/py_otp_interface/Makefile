# New ports collection makefile for:	py_otp_interface
# Date Created:				10 November 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	py_otp_interface
PORTVERSION=	0.92
CATEGORIES=	devel python
MASTER_SITES=	http://www.lysator.liu.se/~tab/erlang/py_interface/
DISTNAME=	py_interface-${PORTVERSION}
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A native python implementation of an Erlang/OTP node

USE_PYTHON=	yes

OTP_LIBS=	erl_async_conn.py erl_common.py erl_epmd.py \
		erl_eventhandler.py erl_node.py erl_node_conn.py \
		erl_opts.py erl_term.py
OTP_EXAMPLES=	test_erl_node.py test_erl_node_conn.py test_erl_epmd.py \
		test_erl_node_tk_1.py
OTP_DOCS=	COPYING.LIB README py_interface.pub

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@for FILE in ${OTP_LIBS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE}* ${PYTHON_SITELIBDIR}; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@for FILE in ${OTP_EXAMPLES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${EXAMPLESDIR}; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${OTP_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>

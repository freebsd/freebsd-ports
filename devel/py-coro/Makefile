# Ports collection Makefile for:	py-coro
# Date created:				06/22/2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=		coro
PORTVERSION=		20010202
CATEGORIES=		devel python
MASTER_SITES=		http://www.dotfunk.com/projects/coro/
PKGNAMEPREFIX=		py-
DISTNAME=		${PORTNAME}_2001_02_02

MAINTAINER=		kbyanc@posi.net

BUILD_DEPENDS=		${LOCALBASE}/lib/libcoro.a:${PORTSDIR}/devel/libcoro

USE_PYTHON=		yes
PLIST_SUB+=		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}
MAKE_ENV=		PYTHON_VERSION=${PYTHON_VERSION:S/python//} \
			EXTRA_INCLUDE="-I${LOCALBASE}/include" \
			EXTRA_LIB="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=		installdir="${PREFIX}" \
			PYTHON="${PYTHON_CMD}" \
			prefix="${PREFIX}"

COROMOD_MAKE=		cd ${WRKSRC}/coromodule && ${MAKE_ENV} ${MAKE}
CORO_PACKAGE=		__init__ coro corodns coro_fd coro_subproc corodevice \
			dnsclass dnslib dnsopcode dnstype fifo
CORO_EXAMPLES= 		backdoor coro_fd coro_subproc coro_ehttpd \
			corohttpd

do-configure:
	@${COROMOD_MAKE} -f Makefile.pre.in boot ${CONFIGURE_ARGS}

do-build:
	@${COROMOD_MAKE}

	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${COROMOD_MAKE} install

	${MKDIR} ${PYTHON_SITELIBDIR}
	${MKDIR} ${PYTHON_SITELIBDIR}/coro
	${MKDIR} ${PREFIX}/share/examples/py-coro
.for i in ${CORO_PACKAGE}
	${INSTALL_DATA} ${WRKSRC}/${i}.py* \
		${PYTHON_SITELIBDIR}/coro
.endfor
.if !defined(NOPORTDOCS)
.for i in ${CORO_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i}.py* \
		${PREFIX}/share/examples/py-coro
.endfor
.endif

.include <bsd.port.mk>

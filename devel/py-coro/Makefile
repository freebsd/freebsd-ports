# Ports collection Makefile for:	py-coro
# Date created:				06/22/2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=		coro
PORTVERSION=		20000424
CATEGORIES=		devel python
MASTER_SITES=		http://www.egroups.com/files/python-coro/egroups/
PKGNAMEPREFIX=		py-
DISTNAME=		egp-coro-20000424

MAINTAINER=		kbyanc@posi.net

BUILD_DEPENDS=		${LOCALBASE}/lib/libcoro.a:${PORTSDIR}/devel/libcoro \
			python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=		python1.5:${PORTSDIR}/lang/python15

CORO_MODULES=		coroutinemodule.so sendfilemodule.so
CORO_PACKAGE=		coro corodns coromysql corourl \
			coutil
CORO_EXAMPLES= 		backdoor potato newpotato fringe \
			coro_ehttpd crawler fifo
CORO_DOCS=		README coro.txt

post-build:
	@${LOCALBASE}/bin/python \
		${LOCALBASE}/lib/python1.5/compileall.py ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/lib/python1.5/site-packages
	${MKDIR} ${PREFIX}/lib/python1.5/site-packages/coro
	${MKDIR} ${PREFIX}/share/examples/py-coro
.for i in ${CORO_MODULES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/lib/python1.5/site-packages
.endfor
.for i in ${CORO_PACKAGE}
	${INSTALL_DATA} ${WRKSRC}/${i}.py ${WRKSRC}/$i.pyc \
		${PREFIX}/lib/python1.5/site-packages/coro
.endfor
.for i in ${CORO_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i}.py ${WRKSRC}/$i.pyc \
		${PREFIX}/share/examples/py-coro
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/py-coro
.for i in ${CORO_DOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/share/doc/py-coro
.endfor
.endif

.include <bsd.port.mk>

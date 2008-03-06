# New ports collection makefile for:	meta-cvs
# Date created:		13 February 2003
# Whom:			johs
#
# $FreeBSD$
#

PORTNAME=	meta-cvs
PORTVERSION=	1.0.13
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://users.footprints.net/~kaz/
DISTNAME=	mcvs-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A more capable version control system than CVS, built around CVS

BUILD_DEPENDS=	clisp:${PORTSDIR}/lang/clisp \
		${LOCALBASE}/lib/libsigsegv.a:${PORTSDIR}/devel/libsigsegv \
		${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall
RUN_DEPENDS=	${LOCALBASE}/lib/libavcall.a:${PORTSDIR}/devel/ffcall

USE_GETTEXT=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} >= 700000
USE_GCC=	3.4
.endif

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/build.sh ${WRKSRC}/code

post-install:
	${SED} 's:PREFIX:${PREFIX}:g' ${FILESDIR}/mcvs.tmpl > ${WRKDIR}/mcvs
	${INSTALL_SCRIPT} ${WRKDIR}/mcvs ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Meta-CVS-PAPER ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICK-GUIDE ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

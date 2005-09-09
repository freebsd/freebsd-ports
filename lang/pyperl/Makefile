# New ports collection makefile for:	pyperl
# Date created:				1 September 2005
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyperl
PORTVERSION=	1.0.1
CATEGORIES=	lang python perl5
MASTER_SITES=	http://downloads.activestate.com/Zope-Perl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Module to embed Perl code into a Python program

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PERL_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/Python-Object
INSTALL_TARGET=	pure_install

MAN3=		Python.3 Python::Err.3 Python::Object.3

post-extract:
	@${RM} -f ${WRKSRC}/MULTI_PERL

post-configure:
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

post-build:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires PERL 5.6.0 or better
.endif

.include <bsd.port.post.mk>

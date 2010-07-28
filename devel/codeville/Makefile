# New ports collection makefile for:	Codeville
# Date created:		Wed Dec  8 01:00:39 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	codeville
PORTVERSION=	0.1.16
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://codeville.org/download/
DISTNAME=	Codeville-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An "anarchic" control version system without unnecessary re-merges

DEPRECATED=	Dead project.
EXPIRATION_DATE=2010-08-31

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Codeville

PORTDOCS=	\
		LICENSE.txt

EXAMPLE_FILES=	\
		cdvserver.conf.sample

post-install:
# examples
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
# documentation
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif

pre-everything::
.ifndef(WITHOUT_PSYCO)
	@${ECHO_MSG} '===> Define WITHOUT_PSYCO to disable devel/py-psyco optimization'
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_PSYCO=  yes
.endif

.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

. for patch in \
		cdv \
		cdv-agent \
		cdvpasswd \
		cdvserver \
		cdvupgrade
EXTRA_PATCHES+= ${FILESDIR}/extra-psyco-patch-${patch}
. endfor
.endif

.include <bsd.port.post.mk>

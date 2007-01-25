# New ports collection makefile for:	tailor
# Date created:				16 June 2006
# Whom:					Rui Lopes <rgl ruilopes com>
#
# $FreeBSD$
#

PORTNAME=	tailor
PORTVERSION=	0.9.27
CATEGORIES=	devel python
MASTER_SITES=	http://darcs.arstecnica.it/

MAINTAINER=	sa2c@sa2c.net
COMMENT=	Migrates changesets between version control systems

RUN_DEPENDS=	${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	README*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README* ${DOCSDIR}
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,${PYTHON_SITELIBDIR:S,^${PYTHONBASE}/,,},%%PYTHON_SITELIBDIR%%,g \
		;s,.*${DOCSDIR:S,${PREFIX}/,,}.*,,g \
		;s,@dirrm (%%PYTHON_SITELIBDIR%%|${PYTHON_LIBDIR:S,${PYTHONBASE}/,,})$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>

# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	funcparserlib
PORTVERSION=	0.3.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Recursive descent parsing library based on functional combinators

LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

PORTDOCS=	README doc
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

OPTIONS_DEFINE=	DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${RM} -f ${WRKSRC}/doc/Makefile
	@${MKDIR} ${DOCSDIR}
	@cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

x-generate-plist:
	${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type f | ${SORT} | \
	${SED} -e 's,${PYTHON_SITELIBDIR},%%PYTHON_SITELIBDIR%%,' > pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PORTNAME} -type d -depth | ${SORT} -r | \
	${SED} -e 's,${PYTHON_SITELIBDIR},@dirrm %%PYTHON_SITELIBDIR%%,' >> pkg-plist.new

.include <bsd.port.mk>

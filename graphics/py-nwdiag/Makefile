# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nwdiag
PORTVERSION=	0.9.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A simple network-diagram image generator

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}imaging>=1.1.5:${PORTSDIR}/graphics/py-imaging \
		${PKGNAMEPREFIX}funcparserlib>=0.3.4:${PORTSDIR}/devel/py-funcparserlib \
		${PKGNAMEPREFIX}blockdiag>=1.2.4:${PORTSDIR}/graphics/py-blockdiag

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

MAN1=	${PORTNAME}.1 rackdiag.1

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	README.txt
PORTEXAMPLES=	*

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/src/${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for d in ${PORTNAME} packetdiag
	@${INSTALL_DATA} \
		${INSTALL_WRKSRC}/examples/${d}/${PORTEXAMPLES} \
		${EXAMPLESDIR}
.endfor
.endif
.for f in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${f} ${MAN1PREFIX}/man/man1/
.endfor

x-generate-plist:
	${ECHO} bin/${PORTNAME} > pkg-plist.new
	${ECHO} bin/packetdiag >> pkg-plist.new
	${ECHO} bin/rackdiag >> pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type f | ${SORT} | \
	${SED} -e 's,${PYTHON_SITELIBDIR},%%PYTHON_SITELIBDIR%%,' \
		-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' \
		>> pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type d -depth | ${SORT} -r | \
	${SED} -e 's,${PYTHON_SITELIBDIR},@dirrm %%PYTHON_SITELIBDIR%%,' \
		-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' \
		>> pkg-plist.new

.include <bsd.port.mk>

PORTNAME=	redeclipse-data
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Data files for Red Eclipse first-person shooter

CONFLICTS_INSTALL=redeclipse-data16

USE_GITHUB=	nodefault

.include "${.CURDIR}/Makefile.tuples"

NO_BUILD=	yes
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/redeclipse

PORTDATA=	*

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

Makefile.tuples::
	@${ECHO_CMD} '# $$Free''BSD$$' > ${.CURDIR}/Makefile.tuples
	@${RM} -rf ${WRKDIR}/.maintainer.checkout
	@${MKDIR} ${WRKDIR}/.maintainer.checkout \
		&& cd ${WRKDIR}/.maintainer.checkout \
		&& git clone --depth=1 --branch=${DISTVERSIONPREFIX}${PORTVERSION} \
			https://github.com/redeclipse/base.git . \
		&& git submodule \
			| awk '{print substr($$1,2,7), substr($$2,6)}' \
			| awk '{printf("%sredeclipse:%s:%s:%s/%s \\\n", NR==1 ? "GH_TUPLE=\t" : "\t\t", $$2, $$1, $$2, $$2, $$2)}' \
			>> ${.CURDIR}/Makefile.tuples

.include <bsd.port.mk>

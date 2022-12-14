PORTNAME=	gprbuild
PORTVERSION=	${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adacore multi-language software build tool
WWW=		https://www.adacore.com/gems/gem-65

LICENSE=	GPLv3+ GPLv3RLE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING3

BUILD_DEPENDS=	xmlada>=4.4:textproc/xmlada

SNAPSHOT=	20160609
USES=		ada
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_TAGNAME=	376670f

PORTDOCS=	*
MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}
BUILD_WRKSRC=	${WRKSRC}/construction
INSTALL_WRKSRC=	${BUILD_WRKSRC}
INSTALL_TARGET=	install

OPTIONS_DEFINE=	DOCS
#DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
#DOCS_ALL_TARGET=	gen-docs
#DOCS_INSTALL_TARGET=	install-docs

post-patch:
	@${MKDIR} ${BUILD_WRKSRC}
	@${CP} ${FILESDIR}/Makefile.BSD ${BUILD_WRKSRC}/Makefile
	@${REINPLACE_CMD} -i "" -e "s,@AUXPREFIX@,${PREFIX}/${ADAXX}-aux," \
		${WRKSRC}/share/gprconfig/compilers.xml
	@${RM} ${WRKSRC}/share/gprconfig/*.orig

.include <bsd.port.mk>

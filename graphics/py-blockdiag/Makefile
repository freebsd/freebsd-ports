# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blockdiag
PORTVERSION=	1.2.4
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A simple block-diagram image generator

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}imaging>=1.1.5:${PORTSDIR}/graphics/py-imaging \
		${PKGNAMEPREFIX}funcparserlib>=0.3.4:${PORTSDIR}/devel/py-funcparserlib \
		${PKGNAMEPREFIX}ordereddict>0:${PORTSDIR}/devel/py-ordereddict \
		${PKGNAMEPREFIX}webcolors>=0:${PORTSDIR}/graphics/py-webcolors

UNIQUENAME=	py-${PORTNAME}

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

MAN1=	${PORTNAME}.1

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	README.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	IPAFONT PDF
IPAFONT_DESC=	Use IPA Font as default
PDF_DESC=	Enable PDF output

OPTIONS_DEFAULT=	PDF

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDF}
RUN_DEPENDS+=	${PKGNAMEPREFIX}reportlab2>0:${PORTSDIR}/print/py-reportlab2
.endif

.if ${PORT_OPTIONS:MIPAFONT}
RUN_DEPENDS+=	${LOCALBASE}/share/font-ipa/ipag.otf:${PORTSDIR}/japanese/font-ipa
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/src/${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${INSTALL_WRKSRC}/examples/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1/

x-generate-plist:
	${ECHO} bin/blockdiag > pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type f | ${SORT} | \
	${SED} -e 's,${PYTHON_SITELIBDIR},%%PYTHON_SITELIBDIR%%,' \
	-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' >> pkg-plist.new
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} -type d -depth | ${SORT} -r | \
	${SED} -e 's,${PYTHON_SITELIBDIR},@dirrm %%PYTHON_SITELIBDIR%%,' \
	-e 's,${PYEASYINSTALL_EGG},%%PYEASYINSTALL_EGG%%,' >> pkg-plist.new

.include <bsd.port.mk>

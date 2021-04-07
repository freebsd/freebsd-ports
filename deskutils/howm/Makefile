PORTNAME=	howm
PORTVERSION=	1.4.3
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	http://howm.sourceforge.jp/a/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Write fragmentarily and read collectively

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

.if ${FLAVOR:U} == devel_full || ${FLAVOR:U} == devel_nox
BROKEN=		Debugger entered--Lisp error: (wrong-type-argument stringp nil)
.endif

USES=		emacs

GNU_CONFIGURE=	yes

PORTDOCS=	*.html *.png
PORTEXAMPLES=	en/0000-00-00-000000.txt ja/0000-00-00-000000.txt

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_ARCH=	yes

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.png ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/en ${STAGEDIR}${EXAMPLESDIR}/ja
	(cd ${WRKSRC} && ${INSTALL_DATA} ja/0* ${STAGEDIR}${EXAMPLESDIR}/ja)
	(cd ${WRKSRC} && ${INSTALL_DATA} en/0* ${STAGEDIR}${EXAMPLESDIR}/en)

.include <bsd.port.mk>

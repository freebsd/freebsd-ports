# $FreeBSD$

PORTNAME=	howm
PORTVERSION=	1.4.3
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://howm.sourceforge.jp/a/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Write fragmentarily and read collectively

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

.if ${FLAVOR:U} != devel && ${FLAVOR:U} != devel_nox
# http://pkg.awarnach.mathstat.dal.ca/data/11i386-default/2018-05-30_07h36m11s/logs/errors/howm-emacs26-1.4.3_3.log
BROKEN=		fails to build
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
